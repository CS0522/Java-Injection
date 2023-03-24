/*
 * Copyright (c) 2003, 2018, Oracle and/or its affiliates. All rights reserved.
 * ORACLE PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

/**
 * The standard classes and interfaces that a third party vendor has to
 * use in its implementation of a synchronization provider. These classes and
 * interfaces are referred to as the Service Provider Interface (SPI).  To make it possible
 * for a <code>RowSet</code> object to use an implementation, the vendor must register
 * it with the <code>SyncFactory</code> singleton. (See the class comment for
 * <code>SyncProvider</code> for a full explanation of the registration process and
 * the naming convention to be used.)
 *
 * <h2>Table of Contents</h2>
 * <ul>
 * <li><a href="#pkgspec">1.0 Package Specification</a>
 * <li><a href="#arch">2.0 Service Provider Architecture</a>
 * <li><a href="#impl">3.0 Implementer's Guide</a>
 * <li><a href="#resolving">4.0 Resolving Synchronization Conflicts</a>
 * <li><a href="#relspec">5.0 Related Specifications</a>
 * <li><a href="#reldocs">6.0 Related Documentation</a>
 * </ul>
 *
 * <h3><a id="pkgspec">1.0 Package Specification</a></h3>
 * <P>
 * The following classes and interfaces make up the <code>javax.sql.rowset.spi</code>
 * package:
 * <UL>
 *  <LI><code>SyncFactory</code>
 *  <LI><code>SyncProvider</code>
 *  <LI><code>SyncFactoryException</code>
 *  <LI><code>SyncProviderException</code>
 *  <LI><code>SyncResolver</code>
 *  <LI><code>XmlReader</code>
 *  <LI><code>XmlWriter</code>
 *  <LI><code>TransactionalWriter</code>
 * </UL>
 * The following interfaces, in the <code>javax.sql</code> package, are also part of the SPI:
 * <UL>
 *  <LI><code>RowSetReader</code>
 *  <LI><code>RowSetWriter</code>
 * </UL>
 * <P>
 * A <code>SyncProvider</code> implementation provides a disconnected <code>RowSet</code>
 * object with the mechanisms for reading data into it and for writing data that has been
 * modified in it
 * back to the underlying data source.  A <i>reader</i>, a <code>RowSetReader</code> or
 * <code>XMLReader</code> object, reads data into a <code>RowSet</code> object when the
 * <code>CachedRowSet</code> methods <code>execute</code> or <code>populate</code>
 * are called.  A <i>writer</i>, a <code>RowSetWriter</code> or <code>XMLWriter</code>
 * object, writes changes back to the underlying data source when the
 * <code>CachedRowSet</code> method <code>acceptChanges</code> is called.
 * <P>
 * The process of writing changes in a <code>RowSet</code> object to its data source
 * is known as <i>synchronization</i>.  The <code>SyncProvider</code> implementation that a
 * <code>RowSet</code> object is using determines the level of synchronization that the
 * <code>RowSet</code> object's writer uses. The various levels of synchronization are
 * referred to as <i>grades</i>.
 * <P>
 * The lower grades of synchronization are
 * known as <i>optimistic</i> concurrency levels because they optimistically
 * assume that there will be no conflicts or very few conflicts.  A conflict exists when
 * the same data modified in the <code>RowSet</code> object has also been modified
 * in the data source. Using the optimistic concurrency model means that if there
 * is a conflict, modifications to either the data source or the <code>RowSet</code>
 * object will be lost.
 * <P>
 * Higher grades of synchronization are called <i>pessimistic</i> because they assume
 * that others will be accessing the data source and making modifications.  These
 * grades set varying levels of locks to increase the chances that no conflicts
 * occur.
 * <P>
 * The lowest level of synchronization is simply writing any changes made to the
 * <code>RowSet</code> object to its underlying data source.  The writer does
 * nothing to check for conflicts.
 * If there is a conflict and the data
 * source values are overwritten, the changes other parties have made by to the data
 * source are lost.
 * <P>
 * The <code>RIXMLProvider</code> implementation uses the lowest level
 * of synchronization and just writes <code>RowSet</code> changes to the data source.
 *
 * <P>
 * For the next level up, the
 * writer checks to see if there are any conflicts, and if there are,
 * it does not write anything to the data source.  The problem with this concurrency
 * level is that if another party has modified the corresponding data in the data source
 * since the <code>RowSet</code> object got its data,
 * the changes made to the <code>RowSet</code> object are lost. The
 * <code>RIOptimisticProvider</code> implementation uses this level of synchronization.
 * <P>
 * At higher levels of synchronization, referred to as pessimistic concurrency,
 * the writer take steps to avoid conflicts by setting locks. Setting locks
 * can vary from setting a lock on a single row to setting a lock on a table
 * or the entire data source. The level of synchronization is therefore a tradeoff
 * between the ability of users to access the data source concurrently and the  ability
 * of the writer to keep the data in the <code>RowSet</code> object and its data source
 * synchronized.
 * <P>
 * It is a requirement that all disconnected <code>RowSet</code> objects
 * (<code>CachedRowSet</code>, <code>FilteredRowSet</code>, <code>JoinRowSet</code>,
 * and <code>WebRowSet</code> objects) obtain their <code>SyncProvider</code> objects
 * from the <code>SyncFactory</code> mechanism.
 * <P>
 * The reference implementation (RI) provides two synchronization providers.
 *    <UL>
 *       <LI><b><code>RIOptimisticProvider</code></b> <br>
 *            The default provider that the <code>SyncFactory</code> instance will
 *            supply to a disconnected <code>RowSet</code> object when no provider
 *            implementation is specified.<BR>
 *            This synchronization provider uses an optimistic concurrency model,
 *            assuming that there will be few conflicts among users
 *            who are accessing the same data in a database.  It avoids
 *            using locks; rather, it checks to see if there is a conflict
 *            before trying to synchronize the <code>RowSet</code> object and the
 *            data source. If there is a conflict, it does nothing, meaning that
 *            changes to the <code>RowSet</code> object are not persisted to the data
 *            source.
 *        <LI><B><code>RIXMLProvider</code></B> <BR>
 *             A synchronization provider that can be used with a
 *             <code>WebRowSet</code> object, which is a rowset that can be written
 *             in XML format or read from XML format. The
 *             <code>RIXMLProvider</code> implementation does no checking at all for
 *             conflicts and simply writes any updated data in the
 *             <code>WebRowSet</code> object to the underlying data source.
 *             <code>WebRowSet</code> objects use this provider when they are
 *             dealing with XML data.
 *     </UL>
 *
 *  These <code>SyncProvider</code> implementations
 *  are bundled with the reference implementation, which makes them always available to
 *  <code>RowSet</code> implementations.
 *  <code>SyncProvider</code> implementations make themselves available by being
 *  registered with the <code>SyncFactory</code> singleton.  When a <code>RowSet</code>
 *  object requests a provider, by specifying it in the constructor or as an argument to the
 *  <code>CachedRowSet</code> method <code>setSyncProvider</code>,
 *  the <code>SyncFactory</code> singleton
 *  checks to see if the requested provider has been registered with it.
 *  If it has, the <code>SyncFactory</code> creates an instance of it and passes it to the
 *  requesting <code>RowSet</code> object.
 *  If the <code>SyncProvider</code> implementation that is specified has not been registered,
 *  the <code>SyncFactory</code> singleton causes a <code>SyncFactoryException</code> object
 *  to be thrown.  If no provider is specified,
 *  the <code>SyncFactory</code> singleton will create an instance of the default
 *  provider implementation, <code>RIOptimisticProvider</code>,
 *  and pass it to the requesting <code>RowSet</code> object.
 *
 * <P>
 * If a <code>WebRowSet</code> object does not specify a provider in its constructor, the
 * <code>SyncFactory</code> will give it an instance of <code>RIOptimisticProvider</code>.
 * However, the constructor for <code>WebRowSet</code> is implemented to set the provider
 * to the <code>RIXMLProvider</code>, which reads and writes a <code>RowSet</code> object
 *  in XML format.
 *  <P>
 * See the <a href="SyncProvider.html">SyncProvider</a> class
 *  specification for further details.
 * <p>
 * Vendors may develop a <code>SyncProvider</code> implementation with any one of the possible
 * levels of synchronization, thus giving <code>RowSet</code> objects a choice of
 * synchronization mechanisms.
 *
 * <h3><a id="arch">2.0 Service Provider Interface Architecture</a></h3>
 * <b>2.1 Overview</b>
 * <p>
 * The Service Provider Interface provides a pluggable mechanism by which
 * <code>SyncProvider</code> implementations can be registered and then generated when
 * required. The lazy reference mechanism employed by the <code>SyncFactory</code> limits
 * unnecessary resource consumption by not creating an instance until it is
 * required by a disconnected
 * <code>RowSet</code> object. The <code>SyncFactory</code> class also provides
 * a standard API to configure logging options and streams that <b>may</b> be provided
 * by a particular <code>SyncProvider</code> implementation.
 * <p>
 * <b>2.2 Registering with the <code>SyncFactory</code></b>
 * <p>
 * A third party <code>SyncProvider</code> implementation must be registered with the
 * <code>SyncFactory</code> in order for a disconnected <code>RowSet</code> object
 * to obtain it and thereby use its <code>javax.sql.RowSetReader</code> and
 * <code>javax.sql.RowSetWriter</code>
 * implementations. The following registration mechanisms are available to all
 * <code>SyncProvider</code> implementations:
 * <ul>
 * <li><b>System properties</b> - Properties set at the command line. These
 * properties are set at run time and apply system-wide per invocation of the Java
 * application. See the section <a href="#reldocs">"Related Documentation"</a>
 * further related information.
 *
 * <li><b>Property Files</b> - Properties specified in a standard property file.
 * This can be specified using a System Property or by modifying a standard
 * property file located in the platform run-time. The
 * reference implementation of this technology includes a standard property
 * file than can be edited to add additional <code>SyncProvider</code> objects.
 *
 * <li><b>JNDI Context</b> - Available providers can be registered on a JNDI
 * context. The <code>SyncFactory</code> will attempt to load <code>SyncProvider</code>
 * objects bound to the context and register them with the factory. This
 * context must be supplied to the <code>SyncFactory</code> for the mechanism to
 * function correctly.
 * </ul>
 * <p>
 * Details on how to specify the system properties or properties in a property file
 * and how to configure the JNDI Context are explained in detail in the
 * <a href="SyncFactory.html"><code>SyncFactory</code></a> class description.
 * <p>
 * <b>2.3 SyncFactory Provider Instance Generation Policies</b>
 * <p>
 * The <code>SyncFactory</code> generates a requested <code>SyncProvider</code>
 * object if the provider has been correctly registered.  The
 * following policies are adhered to when either a disconnected <code>RowSet</code> object
 * is instantiated with a specified <code>SyncProvider</code> implementation or is
 * reconfigured at runtime with an alternative <code>SyncProvider</code> object.
 * <ul>
 * <li> If a <code>SyncProvider</code> object is specified and the <code>SyncFactory</code>
 * contains <i>no</i> reference to the provider, a <code>SyncFactoryException</code> is
 * thrown.
 *
 * <li> If a <code>SyncProvider</code> object is specified and the <code>SyncFactory</code>
 * contains a reference to the provider, the requested provider is supplied.
 *
 * <li> If no <code>SyncProvider</code> object is specified, the reference
 * implementation provider <code>RIOptimisticProvider</code> is supplied.
 * </ul>
 * <p>
 * These policies are explored in more detail in the <a href="SyncFactory.html">
 * <code>SyncFactory</code></a> class.
 *
 * <h3><a id="impl">3.0 SyncProvider Implementer's Guide</a></h3>
 *
 * <b>3.1 Requirements</b>
 * <p>
 * A compliant <code>SyncProvider</code> implementation that is fully pluggable
 * into the <code>SyncFactory</code> <b>must</b> extend and implement all
 * abstract methods in the <a href="SyncProvider.html"><code>SyncProvider</code></a>
 * class. In addition, an implementation <b>must</b> determine the
 * grade, locking and updatable view capabilities defined in the
 * <code>SyncProvider</code> class definition. One or more of the
 * <code>SyncProvider</code> description criteria <b>must</b> be supported. It
 * is expected that vendor implementations will offer a range of grade, locking, and
 * updatable view capabilities.
 * <p>
 * Furthermore, the <code>SyncProvider</code> naming convention <b>must</b> be followed as
 * detailed in the <a href="SyncProvider.html"><code>SyncProvider</code></a> class
 * description.
 * <p>
 * <b>3.2 Grades</b>
 * <p>
 * JSR 114 defines a set of grades to describe the quality of synchronization
 * a <code>SyncProvider</code> object can offer a disconnected <code>RowSet</code>
 * object. These grades are listed from the lowest quality of service to the highest.
 * <ul>
 * <li><b>GRADE_NONE</b> - No synchronization with the originating data source is
 * provided. A <code>SyncProvider</code> implementation returning this grade will simply
 * attempt to write any data that has changed in the <code>RowSet</code> object to the
 *underlying data source, overwriting whatever is there. No attempt is made to compare
 * original values with current values to see if there is a conflict. The
 * <code>RIXMLProvider</code> is implemented with this grade.
 *
 * <li><b>GRADE_CHECK_MODIFIED_AT_COMMIT</b> - A low grade of optimistic synchronization.
 * A <code>SyncProvider</code> implementation returning this grade
 * will check for conflicts in rows that have changed between the last synchronization
 * and the current synchronization under way. Any changes in the originating data source
 * that have been modified will not be reflected in the disconnected <code>RowSet</code>
 * object. If there are no conflicts, changes in the <code>RowSet</code> object will be
 * written to the data source. If there are conflicts, no changes are written.
 * The <code>RIOptimisticProvider</code> implementation uses this grade.
 *
 * <li><b>GRADE_CHECK_ALL_AT_COMMIT</b> - A high grade of optimistic synchronization.
 * A <code>SyncProvider</code> implementation   returning this grade
 * will check all rows, including rows that have not changed in the disconnected
 * <code>RowSet</code> object. In this way, any changes to rows in the underlying
 * data source will be reflected in the disconnected <code>RowSet</code> object
 * when the synchronization finishes successfully.
 *
 * <li><b>GRADE_LOCK_WHEN_MODIFIED</b> - A pessimistic grade of synchronization.
 * <code>SyncProvider</code> implementations returning this grade will lock
 * the row in the originating  data source that corresponds to the row being changed
 * in the <code>RowSet</code> object to reduce the possibility of other
 * processes modifying the same data in the data source.
 *
 * <li><b>GRADE_LOCK_WHEN_LOADED</b> - A higher pessimistic synchronization grade.
 * A <code>SyncProvider</code> implementation returning this grade will lock
 * the entire view and/or  table affected by the original query used to
 * populate a <code>RowSet</code> object.
 * </ul>
 * <p>
 * <b>3.3 Locks</b>
 * <p>
 * JSR 114 defines a set of constants that specify whether any locks have been
 * placed on a <code>RowSet</code> object's underlying data source and, if so,
 * on which constructs the locks are placed.  These locks will remain on the data
 * source while the <code>RowSet</code> object is disconnected from the data source.
 * <P>
 * These constants <b>should</b> be considered complementary to the
 * grade constants. The default setting for the majority of grade settings requires
 * that no data source locks remain when a <code>RowSet</code> object is disconnected
 * from its data source.
 * The grades <code>GRADE_LOCK_WHEN_MODIFIED</code> and
 * <code>GRADE_LOCK_WHEN_LOADED</code> allow a disconnected <code>RowSet</code> object
 * to have a fine-grained control over the degree of locking.
 * <ul>
 * <li><b>DATASOURCE_NO_LOCK</b> - No locks remain on the originating data source.
 * This is the default lock setting for all <code>SyncProvider</code> implementations
 * unless otherwise directed by a <code>RowSet</code> object.
 *
 * <li><b>DATASOURCE_ROW_LOCK</b> - A lock is placed on the rows that are touched by
 * the original SQL query used to populate the <code>RowSet</code> object.
 *
 * <li><b>DATASOURCE_TABLE_LOCK</b> - A lock is placed on all tables that are touched
 * by the query that was used to populate the <code>RowSet</code> object.
 *
 * <li><b>DATASOURCE_DB_LOCK</b>
 * A lock is placed on the entire data source that is used by the <code>RowSet</code>
 * object.
 * </ul>
 * <p>
 * <b>3.4 Updatable Views</b>
 * <p>
 * A <code>RowSet</code> object may be populated with data from an SQL <code>VIEW</code>.
 * The following constants indicate whether a <code>SyncProvider</code> object can
 * update data in the table or tables from which the <code>VIEW</code> was derived.
 * <ul>
 * <li><b>UPDATABLE_VIEW_SYNC</b>
 * Indicates that a <code>SyncProvider</code> implementation  supports synchronization
 * to the table or tables from which the SQL <code>VIEW</code> used to populate
 * a <code>RowSet</code> object is derived.
 *
 * <li><b>NONUPDATABLE_VIEW_SYNC</b>
 * Indicates that a <code>SyncProvider</code> implementation  does <b>not</b> support
 * synchronization to the table or tables from which the SQL <code>VIEW</code>
 * used to populate  a <code>RowSet</code> object is derived.
 * </ul>
 * <p>
 * <b>3.5 Usage of <code>SyncProvider</code> Grading and Locking</b>
 * <p>
 * In the example below, the reference <code>CachedRowSetImpl</code> implementation
 * reconfigures its current <code>SyncProvider</code> object by calling the
 * <code>setSyncProvider</code> method.<br>
 *
 * <PRE>
 *   CachedRowSetImpl crs = new CachedRowSetImpl();
 *   crs.setSyncProvider("com.foo.bar.HASyncProvider");
 * </PRE>
 *   An application can retrieve the <code>SyncProvider</code> object currently in use
 * by a disconnected <code>RowSet</code> object. It can also retrieve the
 * grade of synchronization with which the provider was implemented and the degree of
 * locking currently in use.  In addition, an application has the flexibility to set
 * the degree of locking to be used, which can increase the possibilities for successful
 * synchronization.  These operation are shown in the following code fragment.
 * <PRE>
 *   SyncProvider sync = crs.getSyncProvider();
 *
 *   switch (sync.getProviderGrade()) {
 *   case: SyncProvider.GRADE_CHECK_ALL_AT_COMMIT
 *         //A high grade of optimistic synchronization
 *    break;
 *    case: SyncProvider.GRADE_CHECK_MODIFIED_AT_COMMIT
 *         //A low grade of optimistic synchronization
 *    break;
 *    case: SyncProvider.GRADE_LOCK_WHEN_LOADED
 *         // A pessimistic synchronization grade
 *    break;
 *    case: SyncProvider.GRADE_LOCK_WHEN_MODIFIED
 *         // A pessimistic synchronization grade
 *    break;
 *    case: SyncProvider.GRADE_NONE
 *      // No synchronization with the originating data source provided
 *    break;
 *    }
 *
 *    switch (sync.getDataSourcLock() {
 *      case: SyncProvider.DATASOURCE_DB_LOCK
 *       // A lock is placed on the entire datasource that is used by the
 *       // <code>RowSet</code> object
 *       break;
 *
 *      case: SyncProvider.DATASOURCE_NO_LOCK
 *       // No locks remain on the  originating data source.
 *      break;
 *
 *      case: SyncProvider.DATASOURCE_ROW_LOCK
 *       // A lock is placed on the rows that are  touched by the original
 *       // SQL statement used to populate
 *       // the RowSet object that is using the SyncProvider
 *       break;
 *
 *      case: DATASOURCE_TABLE_LOCK
 *       // A lock is placed on  all tables that are touched by the original
 *       // SQL statement used to populated
 *       // the RowSet object that is using the SyncProvider
 *      break;
 *
 * </PRE>
 *    It is also possible using the static utility method in the
 * <code>SyncFactory</code> class to determine the list of <code>SyncProvider</code>
 * implementations currently registered with the <code>SyncFactory</code>.
 *
 * <pre>
 *       Enumeration e = SyncFactory.getRegisteredProviders();
 * </pre>
 *
 *
 * <h3><a id="resolving">4.0 Resolving Synchronization Conflicts</a></h3>
 *
 * The interface <code>SyncResolver</code> provides a way for an application to
 * decide manually what to do when a conflict occurs. When the <code>CachedRowSet</code>
 * method <code>acceptChanges</code> finishes and has detected one or more conflicts,
 * it throws a <code>SyncProviderException</code> object.  An application can
 * catch the exception and
 * have it retrieve a <code>SyncResolver</code> object by calling the method
 * <code>SyncProviderException.getSyncResolver()</code>.
 * <P>
 * A <code>SyncResolver</code> object, which is a special kind of
 * <code>CachedRowSet</code> object or
 * a <code>JdbcRowSet</code> object that has implemented the <code>SyncResolver</code>
 * interface,  examines the conflicts row by row. It is a duplicate of the
 * <code>RowSet</code> object being synchronized except that it contains only the data
 * from the data source this is causing a conflict. All of the other column values are
 * set to <code>null</code>. To navigate from one conflict value to another, a
 * <code>SyncResolver</code> object provides the methods <code>nextConflict</code> and
 * <code>previousConflict</code>.
 * <P>
 * The <code>SyncResolver</code> interface also
 * provides methods for doing the following:
 * <UL>
 *  <LI>finding out whether the conflict involved an update, a delete, or an insert
 *  <LI>getting the value in the data source that caused the conflict
 *  <LI>setting the value that should be in the data source if it needs to be changed
 *      or setting the value that should be in the <code>RowSet</code> object if it needs
 *      to be changed
 * </UL>
 * <P>
 * When the <code>CachedRowSet</code> method <code>acceptChanges</code> is called, it
 * delegates to the <code>RowSet</code> object's  <code>SyncProvider</code> object.
 * How the writer provided by that <code>SyncProvider</code> object is implemented
 * determines what level (grade) of checking for conflicts will be done.  After all
 * checking for conflicts is completed and one or more conflicts has been found, the method
 * <code>acceptChanges</code> throws a <code>SyncProviderException</code> object. The
 * application can catch the exception and use it to obtain a <code>SyncResolver</code> object.
 * <P>
 * The application can then use <code>SyncResolver</code> methods to get information
 * about each conflict and decide what to do.  If the application logic or the user
 * decides that a value in the <code>RowSet</code> object should be the one to
 * persist, the application or user can overwrite the data source value with it.
 * <P>
 * The comment for the <code>SyncResolver</code> interface has more detail.
 *
 * <h3><a id="relspec">5.0 Related Specifications</a></h3>
 * <ul>
 * <li><a href="http://docs.oracle.com/javase/jndi/tutorial/index.html">JNDI</a>
 * <li><a href="{@docRoot}/java.logging/java/util/logging/package-summary.html">Java Logging
 * APIs</a>
 * </ul>
 * <h3><a id="reldocs">6.0 Related Documentation</a></h3>
 * <ul>
 * <li><a href="http://docs.oracle.com/javase/tutorial/jdbc/">DataSource for JDBC
 * Connections</a>
 * </ul>
 */
package javax.sql.rowset.spi;
