import java.util.concurrent.Semaphore;

/*
 * This program uses a shared struck as well as a (binary) semaphore
 */

public class SharedCounterArrayGlobalWhile_Semaphore {
  
    static int numThreads = 4;

    public static void main(String[] args) {

    	SharedObj counter = new SharedObj();
    	
        CounterThread threads[] = new CounterThread[numThreads];
	
		for (int i = 0; i < numThreads; i++) {
			threads[i] = new CounterThread(counter);
			threads[i].start();
		}
	
		for (int i = 0; i < numThreads; i++) {
			try {
				threads[i].join();
			}
			catch (InterruptedException e) {}
		} 
        check_array (counter);
    }
     
    static void check_array (SharedObj counter)  {
		int i, errors = 0;
		

		System.out.println ("Checking...");

        for (i = 0; i < counter.end; i++) {
			if (counter.array[i] != 1) {
				errors++;
				System.out.printf("%d: %d should be 1\n", i, counter.array[i]);
			}         
		}
        System.out.println (errors+" errors.");
    }

    static class SharedObj {
    	
    	static int end = 1000;
        static int counter = 0;
        static int[] array = new int[end];
        
        public SharedObj() {
        }
    	
        public void inc(int position) {
        	array[position] = array[position] + 1;
        	counter++;
        }
        
    }
    
    
    static class CounterThread extends Thread {
  	
    	SharedObj counter;
        static Semaphore sem = new Semaphore(1);
    	
       public CounterThread(SharedObj aCounter) {
    	   this.counter = aCounter;
       }
  	
       public void run() {
       
    	   try {
       		sem.acquire();
       	} catch (InterruptedException e) {}
            while (true) {
				if (counter.counter >= counter.end) 
                	break;
            	counter.inc(counter.counter);
            }
        	sem.release();
		}            	
    }
}
  
