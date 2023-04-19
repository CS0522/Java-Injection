package .home.frank.下载.src-code.tomcat-api.org.apache.tomcat;

import java.lang.reflect.InvocationTargetException;
import javax.naming.NamingException;

public interface InstanceManager {
  Object newInstance(String paramString) throws IllegalAccessException, InvocationTargetException, NamingException, InstantiationException, ClassNotFoundException;
  
  Object newInstance(String paramString, ClassLoader paramClassLoader) throws IllegalAccessException, InvocationTargetException, NamingException, InstantiationException, ClassNotFoundException;
  
  void newInstance(Object paramObject) throws IllegalAccessException, InvocationTargetException, NamingException;
  
  void destroyInstance(Object paramObject) throws IllegalAccessException, InvocationTargetException;
}
