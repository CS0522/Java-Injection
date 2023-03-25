package .home.frank.下载.src-code.javax.persistence-api.javax.persistence;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.net.URL;
import java.util.Enumeration;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javax.persistence.EntityManagerFactory;
import javax.persistence.PersistenceException;
import javax.persistence.spi.PersistenceProvider;

public class Persistence {
  public static final String PERSISTENCE_PROVIDER = "javax.persistence.spi.PeristenceProvider";
  
  protected static final Set<PersistenceProvider> providers = new HashSet<PersistenceProvider>();
  
  private static final String SERVICE_NAME = "META-INF/services/" + PersistenceProvider.class.getName();
  
  private static final String PERSISTENCE_XML_NAME = "META-INF/persistence.xml";
  
  public static EntityManagerFactory createEntityManagerFactory(String persistenceUnitName) {
    return createEntityManagerFactory(persistenceUnitName, null);
  }
  
  public static EntityManagerFactory createEntityManagerFactory(String persistenceUnitName, Map properties) {
    EntityManagerFactory emf = null;
    Set<PersistenceProvider> providersFound = null;
    try {
      providersFound = findAllProviders();
    } catch (IOException exc) {}
    Map<String, String> errors = new HashMap<String, String>();
    Set<String> returnedNull = new HashSet<String>();
    for (PersistenceProvider provider : providersFound) {
      try {
        emf = provider.createEntityManagerFactory(persistenceUnitName, properties);
        if (emf != null)
          break; 
        returnedNull.add(provider.getClass().getName());
      } catch (Throwable t) {
        errors.put(provider.getClass().getName(), createErrorMessage(t));
      } 
    } 
    if (emf == null) {
      StringBuffer message = new StringBuffer("No Persistence provider for EntityManager named " + persistenceUnitName + ": ");
      if (!exists("META-INF/persistence.xml")) {
        message.append(" No META-INF/persistence.xml was found in classpath.\n");
      } else {
        Map<String, String> reasons = getReasons();
        for (Map.Entry<String, String> me : reasons.entrySet()) {
          message.append("Provider named ");
          message.append(me.getKey());
          message.append(" threw exception at initialization: ");
          message.append((new StringBuilder()).append(me.getValue()).append("\n").toString());
        } 
        for (Map.Entry<String, String> me : errors.entrySet()) {
          message.append("Provider named ");
          message.append(me.getKey());
          message.append(" threw unexpected exception at create EntityManagerFactory: \n");
          message.append((new StringBuilder()).append(me.getValue()).append("\n").toString());
        } 
        if (!returnedNull.isEmpty()) {
          message.append(" The following providers:\n");
          for (String n : returnedNull)
            message.append(n + "\n"); 
          message.append("Returned null to createEntityManagerFactory.\n");
        } 
      } 
      throw new PersistenceException(message.toString());
    } 
    return emf;
  }
  
  private static Set<PersistenceProvider> findAllProviders() throws IOException {
    HashSet<PersistenceProvider> providersFound = new HashSet<PersistenceProvider>();
    ClassLoader loader = Thread.currentThread().getContextClassLoader();
    Enumeration<URL> resources = loader.getResources(SERVICE_NAME);
    if (!resources.hasMoreElements())
      throw new PersistenceException("No resource files named " + SERVICE_NAME + " were found. Please make sure that the persistence provider jar file is in your classpath."); 
    Set<String> names = new HashSet<String>();
    while (resources.hasMoreElements()) {
      URL url = resources.nextElement();
      InputStream is = url.openStream();
      try {
        names.addAll(providerNamesFromReader(new BufferedReader(new InputStreamReader(is))));
      } finally {
        is.close();
      } 
    } 
    if (names.isEmpty())
      throw new PersistenceException("No provider names were found in " + SERVICE_NAME); 
    for (String s : names) {
      try {
        providersFound.add((PersistenceProvider)loader.loadClass(s).newInstance());
      } catch (ClassNotFoundException exc) {
      
      } catch (InstantiationException exc) {
      
      } catch (IllegalAccessException exc) {}
    } 
    return providersFound;
  }
  
  private static final Pattern nonCommentPattern = Pattern.compile("^([^#]+)");
  
  private static Set<String> providerNamesFromReader(BufferedReader reader) throws IOException {
    Set<String> names = new HashSet<String>();
    String line;
    while ((line = reader.readLine()) != null) {
      line = line.trim();
      Matcher m = nonCommentPattern.matcher(line);
      if (m.find())
        names.add(m.group().trim()); 
    } 
    return names;
  }
  
  private static boolean exists(String fileName) {
    Enumeration enumeration;
    ClassLoader loader = Thread.currentThread().getContextClassLoader();
    try {
      enumeration = loader.getResources(fileName);
    } catch (IOException ex) {
      enumeration = null;
    } 
    return (enumeration == null) ? false : enumeration.hasMoreElements();
  }
  
  private static Map<String, String> getReasons() {
    Map<String, String> reasons = new HashMap<String, String>();
    ClassLoader loader = Thread.currentThread().getContextClassLoader();
    Set<String> names = new HashSet<String>();
    try {
      Enumeration<URL> resources = loader.getResources(SERVICE_NAME);
      while (resources.hasMoreElements()) {
        URL url = resources.nextElement();
        InputStream is = url.openStream();
        try {
          names.addAll(providerNamesFromReader(new BufferedReader(new InputStreamReader(is))));
        } finally {
          is.close();
        } 
      } 
    } catch (IOException exc) {}
    for (String s : names) {
      try {
        loader.loadClass(s).newInstance();
      } catch (ClassNotFoundException exc) {
        reasons.put(s, exc.getClass().getName() + " " + exc.getMessage());
      } catch (InstantiationException exc) {
        reasons.put(s, createErrorMessage(exc));
      } catch (IllegalAccessException exc) {
        reasons.put(s, createErrorMessage(exc));
      } catch (RuntimeException exc) {
        reasons.put(s, createErrorMessage(exc));
      } 
    } 
    return reasons;
  }
  
  private static String createErrorMessage(Throwable t) {
    StringWriter errorMessage = new StringWriter();
    errorMessage.append(t.getClass().getName()).append("\r\n");
    t.printStackTrace(new PrintWriter(errorMessage));
    errorMessage.append("\r\n");
    return errorMessage.toString();
  }
}
