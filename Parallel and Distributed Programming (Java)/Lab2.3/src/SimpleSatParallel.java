import java.lang.Math;

//FINISHED
/*
 * This program is the simple parallel version of SimpleSat using static distribution
 * 2 new global attributes where used {size, numofThreads}. 
 * Someone can change the numofThreads to 4,8,12...etc to see the small differences 
 * when it comes to performance. 
 * DONT TRY TO CHANGE THE SIZE above 28 because its going to cause the JVM heap to "overflow"  
 */


public class SimpleSatParallel {

	static int counter = 0;
	//instead of passing them as arguments on the thread object
	//make them global attributes
	static final int size = 23;
    static final int numofThreads = 8;
	
    public static void main(String[] args) {  
        
        

        int iterations = (int) Math.pow(2, size);
        // Saves Results
        String[] output = new String[iterations];
        
        long start = System.currentTimeMillis();
        
        //thread creation
        threadSat threads[] = new threadSat[numofThreads];
        for(int i=0;i<numofThreads;i++) {
        	threads[i] = new threadSat(i, output, iterations);
        	threads[i].start();
        }
        
        for (int i = 0; i < numofThreads; i++) {
            try {
				threads[i].join();
            }
            catch (InterruptedException e) {}
        }
        
           
        long elapsedTimeMillis = System.currentTimeMillis()-start;
        
        
        for (int i = 0; i < counter; i++)
			System.out.println(output[i]);
        
        System.out.println ("All done\n");
        System.out.println("time in ms = "+ elapsedTimeMillis);
        
    }
    
    static class threadSat extends Thread {
    	
    	int threadN;
    	int start;
    	int stop;
    	int threadID;
    	int iteration;
    	String[] output;
    	
		public threadSat(int aBlock, String[] output, int iter) {
			start = aBlock * (iter/numofThreads);
			stop = start + (iter/numofThreads);
			if(aBlock == size-1) stop = iter;
			this.threadID = aBlock;
			this.iteration = iter;
			this.output = output;
		}
		
		public void run() {
			for(int i=start;i<stop;i++) {
				check_circuit(i, size, output);
			} 
		}
    }
        
    static void check_circuit (int z, int size, String[] output) {
        
		boolean[] v = new boolean[size];  /* Each element is a bit of z */
    
		for (int i = size-1; i >= 0; i--) 
			v[i] = (z & (1 << i)) != 0;
    
       
       boolean value = 
           (  v[0]  ||  v[1]  )
        && ( !v[1]  || !v[3]  )
        && (  v[2]  ||  v[3]  )
        && ( !v[3]  || !v[4]  )
        && (  v[4]  || !v[5]  )
        && (  v[5]  || !v[6]  )
        && (  v[5]  ||  v[6]  )
        && (  v[6]  || !v[15] )
        && (  v[7]  || !v[8]  )
        && ( !v[7]  || !v[13] )
        && (  v[8]  ||  v[9]  )
        && (  v[8]  || !v[9]  )
        && ( !v[9]  || !v[10] )
        && (  v[9]  ||  v[11] )
        && (  v[10] ||  v[11] )
        && (  v[12] ||  v[13] )
        && (  v[13] || !v[14] )
        && (  v[14] ||  v[15] )
        && (  v[14] ||  v[16] )
        && (  v[17] ||  v[1]  )
        && (  v[18] || !v[0]  )
        && (  v[19] ||  v[1]  )
        && (  v[19] || !v[18] )
        && ( !v[19] || !v[9]  )
        && (  v[0]  ||  v[17] )
        && ( !v[1]  ||  v[20] )
        && ( !v[21] ||  v[20] )
        && ( !v[22] ||  v[20] )
        && ( !v[21] || !v[20] )
        && (  v[22] || !v[20] );
        
        
        if (value) {
			printResult(v, size, z, output, counter);
			counter++;
		}	
    }
    
    static void printResult (boolean[] v, int size, int z, String[] output, int counter) {
		
		String result = null;
		result = String.valueOf(z);

		for (int i=0; i< size; i++)
			if (v[i]) result += " 1";
			else result += " 0";
			
		//System.out.println(result);
		output[counter] = result;
	}	   
}
