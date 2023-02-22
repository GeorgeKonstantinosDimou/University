/*
 * This program tries to use the "hack", the solution between lock and
 * synchronized presented in the SimpleProgramWithThreadsSharedSyncLockObj.java
 */

public class SharedCounterArrayGlobalWhile_Sync {
  
    static int end = 100;
    static int numThreads = 4;

    public static void main(String[] args) {
	
    	SharedObj coun = new SharedObj();
    	
        CounterThread threads[] = new CounterThread[numThreads];
	
		for (int i = 0; i < numThreads; i++) {
			threads[i] = new CounterThread(coun);
			threads[i].start();
		}
	
		for (int i = 0; i < numThreads; i++) {
			try {
				threads[i].join();
			}
			catch (InterruptedException e) {}
		} 
        check_array (coun);
    }
     
    static void check_array (SharedObj coun)  {
		int i, errors = 0;

		System.out.println ("Checking...");

        for (i = 0; i < end; i++) {
			if (coun.array[i] != 1) {
				errors++;
				System.out.printf("%d: %d should be 1\n", i, coun.array[i]);
			}         
		}
        System.out.println (errors+" errors.");
    }

    
    static class SharedObj {
    	
    	static int[] array = new int[end];
    	static int counter;
    	
    	Object lock1 = new Object();
    	
    	public SharedObj(){
    		this.counter = 0;
    	}
    	
    	public void inc(int position) {
    		synchronized(lock1) {
    			array[position] = array[position] + 1;
    			counter++;
    		}
    	}
    	
    }

    static class CounterThread extends Thread {
  	
    	
    	SharedObj shCounter; 
    	
       public CounterThread(SharedObj sharedCounter ) {
    	   this.shCounter = sharedCounter;
       }
  	
       public void run() {
       
            while (true) {
				if (shCounter.counter >= end) 
                	break;
            	shCounter.inc(shCounter.counter);	
            } 
		}            	
    }
}
  
