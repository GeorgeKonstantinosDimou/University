/*
 * This program uses the java synchronized method of Mutex
 */

public class SharedCounterArrayGlobal_Sync_withSharedObj {
  
    
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
     
    static void check_array (SharedObj c)  {
		int i, errors = 0;
		

		System.out.println ("Checking...");

        for (i = 0; i < c.end; i++) {
			if (c.array[i] != numThreads*i) {
				errors++;
				System.out.printf("%d: %d should be %d\n", i, c.array[i], numThreads*i);
			}         
        }
        System.out.println (errors+" errors.");
    }

    //a sharedObj to utilize the synchronized on the inc method
    //could instead be used not on the whole method but on a single
    //block inside the method 
    static class SharedObj {
    	
    	static int end = 1000;
        static int[] array = new int[end];
        
        public SharedObj() {
        }
        
        public synchronized void inc(int position) {
        	array[position] = array[position] + 1;
        }
    	
    }

    static class CounterThread extends Thread {
  	
       SharedObj counter;
    	
       public CounterThread(SharedObj aCounter) {
    	   this.counter = aCounter;
       }
  	
       public void run() {
  
            for (int i = 0; i < counter.end; i++) {
				for (int j = 0; j < i; j++)
					counter.inc(i);		
            } 
		}            	
    }
}
  
