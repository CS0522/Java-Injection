/*
 * $Id: BaseAction.java 471754 2006-11-06 14:55:09Z husted $
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

package org.apache.struts.apps.mailreader.actions;

import org.apache.commons.beanutils.PropertyUtils;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.action.ActionMessage;
import org.apache.struts.action.ActionMessages;
import org.apache.struts.action.DynaActionForm;
import org.apache.struts.actions.MappingDispatchAction;
import org.apache.struts.apps.mailreader.Constants;
import org.apache.struts.apps.mailreader.dao.ExpiredPasswordException;
import org.apache.struts.apps.mailreader.dao.Subscription;
import org.apache.struts.apps.mailreader.dao.User;
import org.apache.struts.apps.mailreader.dao.UserDatabase;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;

/**
 * <p>
 * Base Action for MailReader application.
 * </p><p>
 * All the BaseAction helper methods are prefixed with "do"
 * so that they can be easily distinguished from Struts and Servlet API methods.
 * BaseAction subclasses may also have prive "do" helpers of their own.
 * </p><p>
 * Methods are kept in alphabetical order, to make them easier to find.
 * </p>
 *
 * @version $Rev: 471754 $ $Date: 2006-11-06 08:55:09 -0600 (Mon, 06 Nov 2006) $
 */
public abstract class BaseAction extends MappingDispatchAction {

    // ---- Fields ----

    /**
     * <p>
     * Name of username field ["username"].
     * </p>
     */
    public static String USERNAME = "username";

    /**
     * <p>
     * Name of password field ["password"].
     * </p>
     */
    public static String PASSWORD = "password";

    /**
     * <p>
     * Name of task field ["task"].
     * </p>
     */
    public final static String TASK = "task";

    // ---- Protected Variables ----

    /**
     * <p>
     * The <code>Log</code> instance for this application.
     * </p>
     */
    protected Log log = LogFactory.getLog(Constants.PACKAGE);

    // ---- Protected Methods ----

    /**
     * <p>
     * Store User object in client session.
     * If user object is null, any existing user object is removed.
     * </p>
     *
     * @param request The request we are processing
     * @param user    The user object returned from the database
     */
    void doCacheUser(HttpServletRequest request, User user) {

        HttpSession session = request.getSession();
        session.setAttribute(Constants.USER_KEY, user);
        if (log.isDebugEnabled()) {
            log.debug(
                    "LogonAction: User '"
                            + user.getUsername()
                            + "' logged on in session "
                            + session.getId());
        }
    }

    /**
     * <p>
     * Helper method to log event and cancel transaction.
     * </p>
     *
     * @param session Our HttpSession
     * @param method  Method being processed
     * @param key     Attrkibute to remove from session, if any
     */
    protected void doCancel(HttpSession session, String method, String key) {
        if (log.isTraceEnabled()) {
            StringBuffer sb = new StringBuffer(128);
            sb.append(Constants.LOG_CANCEL);
            sb.append(method);
            log.trace(sb.toString());
        }
        if (key != null) {
            session.removeAttribute(key);
        }
    }

    /**
     * <p>
     * Return the local or global forward named "failure"
     * or null if there is no such forward.
     * </p>
     *
     * @param mapping Our ActionMapping
     * @return Return the mapping named "failure" or null if there is no such mapping.
     */
    protected ActionForward doFindFailure(ActionMapping mapping) {
        if (log.isTraceEnabled()) {
            log.trace(Constants.LOG_FAILURE);
        }
        return mapping.findForward(Constants.FAILURE);
    }

    /**
     * <p>
     * Return the local or global forward named "logon"
     * or null if there is no such forward.
     * </p>
     *
     * @param mapping Our ActionMapping
     * @return Return the mapping named "logon" or null if there is no such mapping.
     */
    protected ActionForward doFindLogon(ActionMapping mapping) {
        if (log.isTraceEnabled()) {
            log.trace(Constants.LOG_LOGON);
        }
        return mapping.findForward(Constants.LOGON);
    }

    /**
     * <p>
     * Return the mapping labeled "success"
     * or null if there is no such mapping.
     * </p>
     *
     * @param mapping Our ActionMapping
     * @return Return the mapping named "success" or null if there is no such
     *         mapping.
     */
    protected ActionForward doFindSuccess(ActionMapping mapping) {
        if (log.isTraceEnabled()) {
            log.trace(Constants.LOG_SUCCESS);
        }
        return mapping.findForward(Constants.SUCCESS);
    }

    /**
     * <p>
     * Helper method to fetch a String property from a DynaActionForm.
     * </p>
     * <p>
     * Values are returned trimmed of leading and trailing whitespace.
     * Zero-length strings are returned as null.
     * </p>
     *
     * @param form     Our DynaActionForm
     * @param property The name of the property
     * @return The value or null if an error occurs
     */
    protected String doGet(ActionForm form, String property) {
        String initial;
        try {
            initial = (String) PropertyUtils.getSimpleProperty(form, property);
        } catch (Throwable t) {
            initial = null;
        }
        String value = null;
        if ((initial != null) && (initial.length() > 0)) {
            value = initial.trim();
            if (value.length() == 0) {
                value = null;
            }
        }
        return value;
    }

    /**
     * <p>
     * Obtain the cached Subscription object, if any.
     * </p>
     *
     * @param session Our HttpSession
     * @return Cached Subscription object or null
     */
    protected Subscription doGetSubscription(HttpSession session) {
        return (Subscription) session.getAttribute(Constants.SUBSCRIPTION_KEY);
    }

    /**
     * <p>
     * Obtain the cached Subscription object, if any.
     * </p>
     *
     * @param request Our HttpServletRequest
     * @return Cached Subscription object or null
     */
    protected Subscription doGetSubscription(HttpServletRequest request) {
        HttpSession session = request.getSession();
        return doGetSubscription(session);
    }

    /**
     * <p>
     * Confirm user credentials. Post any errors and return User object
     * (or null).
     * </p>
     *
     * @param database Database in which to look up the user
     * @param username Username specified on the logon form
     * @param password Password specified on the logon form
     * @param errors   ActionMessages queue to passback errors
     * @return Validated User object or null
     * @throws org.apache.struts.apps.mailreader.dao.ExpiredPasswordException
     *          to be handled by Struts exception
     *          processor via the action-mapping
     */
    User doGetUser(UserDatabase database, String username,
                   String password, ActionMessages errors)
            throws ExpiredPasswordException {

        User user = null;
        if (database == null) {
            errors.add(
                    ActionMessages.GLOBAL_MESSAGE,
                    new ActionMessage("error.database.missing"));
        } else {

            if (username.equals("Hermes")) {
                throw new ExpiredPasswordException("Hermes");
            }

            user = database.findUser(username);
            if ((user != null) && !user.getPassword().equals(password)) {
                user = null;
            }
            if (user == null) {
                errors.add(
                        ActionMessages.GLOBAL_MESSAGE,
                        new ActionMessage("error.password.mismatch"));
            }
        }

        return user;
    }

    /**
     * <p>
     * Confirm user credentials. Post any errors and return User object
     * (or null).
     * </p>
     *
     * @param username Username specified on the logon form
     * @param password Password specified on the logon form
     * @param errors   ActionMessages queue to passback errors
     * @return Validated User object or null
     * @throws org.apache.struts.apps.mailreader.dao.ExpiredPasswordException
     *          to be handled by Struts exception
     *          processor via the action-mapping
     */
    User doGetUser(String username,
                   String password, ActionMessages errors)
            throws ExpiredPasswordException {

        return doGetUser(doGetUserDatabase(), username, password, errors);
    }

    /**
     * <p>
     * Return a reference to the UserDatabase
     * or null if the database is not available.
     * </p>
     *
     * @return a reference to the UserDatabase or null if the database is not
     *         available
     */
    protected UserDatabase doGetUserDatabase() {
        return (UserDatabase) servlet.getServletContext().getAttribute(
                Constants.DATABASE_KEY);
    }

    /**
     * <p>
     * Helper method to obtain User form session (if any).
     * </p>
     *
     * @param session Our HttpSession
     * @return User object, or null if there is no user.
     */
    protected User doGetUser(HttpSession session) {
        return (User) session.getAttribute(Constants.USER_KEY);
    }

    /**
     * <p>
     * Helper method to obtain User form session (if any).
     * </p>
     *
     * @param request Our HttpServletRequest
     * @return User object, or null if there is no user.
     */
    protected User doGetUser(HttpServletRequest request) {
        HttpSession session = request.getSession();
        return (User) session.getAttribute(Constants.USER_KEY);
    }

    /**
     * <p>
     * Save any errors and the transactioonal token, and forward to the
     * InputForard result.
     * </p>
     *
     * @param mapping Our ActionMapping
     * @param request Our HttpServletRequest
     * @param errors  Our ActionMessages collectoin
     * @return The InputForward for this mappintg
     */
    protected ActionForward doInputForward(ActionMapping mapping,
                                           HttpServletRequest request,
                                           ActionMessages errors) {
        this.saveErrors(request, errors);
        this.saveToken(request);
        return (mapping.getInputForward());
    }

    /**
     * <p>
     * Log a "processing" message for an Action.
     * </p>
     *
     * @param mapping Our ActionMapping
     * @param method  Name of method being processed
     */
    protected void doLogProcess(ActionMapping mapping, String method) {
        if (log.isDebugEnabled()) {
            StringBuffer sb = new StringBuffer(128);
            sb.append(" ");
            sb.append(mapping.getPath());
            sb.append(":");
            sb.append(Constants.LOG_PROCESSING);
            sb.append(method);
            log.debug(sb.toString());
        }
    }

    /**
     * <p>
     * Helper method to log event and save token.
     * </p>
     *
     * @param request Our HttpServletRequest
     */
    protected void doSaveToken(HttpServletRequest request) {
        if (log.isTraceEnabled()) {
            log.trace(Constants.LOG_TOKEN);
        }
        saveToken(request);
    }

    /**
     * <p>
     * Persist the User object, including subscriptions, to the database.
     * </p>
     *
     * @param user Our User object
     * @throws javax.servlet.ServletException On any error
     */
    protected void doSaveUser(User user) throws ServletException {

        final String LOG_DATABASE_SAVE_ERROR =
                " Unexpected error when saving User: ";

        try {
            UserDatabase database = doGetUserDatabase();
            database.save();
        } catch (Exception e) {
            String message = LOG_DATABASE_SAVE_ERROR + user.getUsername();
            log.error(message, e);
            throw new ServletException(message, e);
        }
    }

    /**
     * <p>
     * Helper method to inject a String property into a DynaActionForm.
     * </p>
     *
     * @param form     Our DynaActionForm
     * @param property The name of the property
     * @param value    The value for the property
     * @return True if the assignment succeeds
     */
    protected boolean doSet(ActionForm form, String property, String value) {
        try {
            DynaActionForm dyna = (DynaActionForm) form;
            dyna.set(property, value);
        } catch (Throwable t) {
            return false;
        }
        return true;
    }

}
