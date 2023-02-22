/*
 * This program uses a shared Object. The original program
 * is the SharedCounterArrayGlobal
 */


public class ShareCounterArraywithDifferentSharedObject {
		  
	    static int numThreads = 4;

	    public static void main(String[] args) {

	    	SharedCounter count = new SharedCounter();
	    	
			CounterThread threads[] = new CounterThread[numThreads];
			
			for (int i = 0; i < numThreads; i++) {
				threads[i] = new CounterThread(count);
				threads[i].start();
			}
		
			for (int i = 0; i < numThreads; i++) {
				try {
					threads[i].join();
				}
				catch (InterruptedException e) {}
			} 
			check_array (count);
	    }
	     
	    static void check_array (SharedCounter count)  {
			int i, errors = 0;

			System.out.println ("Checking...");

	        for (i = 0; i < count.end ; i++) {
				if (count.array[i] != numThreads*i) {
					errors++;
					System.out.printf("%d: %d should be %d\n", i, count.array[i], numThreads*i);
				}         
	        }
	        System.out.println (errors+" errors.");
	    }

	    static class SharedCounter{
	    	
	    	static int end = 1000;
	    	static int[] array = new int[end];
	    	
			public SharedCounter() {
			}
	    	
	    	public void inc(int position) {
	    		array[position] = array[position] + 1;
	    	}
	    	
	    }
	    
	    
	    static class CounterThread extends Thread {
	  	 
	       SharedCounter count;	
	    	
	       public CounterThread(SharedCounter counter) {
	    	   this.count = counter;
	       }
	  	
	       public void run() {
	  
	            for (int i = 0; i < count.end; i++) {
					for (int j = 0; j < i; j++)
						count.inc(i);
	            } 
	       }     
	}
}
