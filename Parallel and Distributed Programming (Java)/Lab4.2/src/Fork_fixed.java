import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/*
 * For the purpose of using different types of Mutual exclusion
 * "synchronized" could be used on the get/put methods 
 */

class Fork_fixed {

  private int identity;
  private Lock lock = new ReentrantLock();

  Fork_fixed(int id)
    {identity = id;}

   void get() {
	   lock.lock();
  }

   void put() {
	   lock.unlock();
  }
}
