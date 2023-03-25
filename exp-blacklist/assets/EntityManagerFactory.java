package .home.frank.下载.src-code.javax.persistence-api.javax.persistence;

import java.util.Map;
import javax.persistence.EntityManager;

public interface EntityManagerFactory {
  EntityManager createEntityManager();
  
  EntityManager createEntityManager(Map paramMap);
  
  void close();
  
  boolean isOpen();
}
