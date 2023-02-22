/*
 * This variation of NumInt get the inspiration from the VecSumGlobalMon
 * in this a shared object is created and operations are handled into it
 */

public class piCalculationSharedObj {

	static final int numThreads = 8;
	static final long numSteps = 100000000;
	
	
    public static void main(String[] args) {

    	
    	piCalcObj sharedObj = new piCalcObj();
    	
        double[] a = new double[(int)numSteps];
        for(int i = 0; i < numSteps; i++)
			a[i] = 0.0;

        /* parse command line */
//        if (args.length != 1) {
//			System.out.println("arguments:  number_of_steps");
//			System.exit(1);
//        }
//        try {
//			numSteps = Long.parseLong(args[0]);
//        } catch (NumberFormatException e) {
//			System.out.println("argument "+ args[0] +" must be long int");
//			System.exit(1);
//        }
        
        /* start timing */
        long startTime = System.currentTimeMillis();
        
        piCalcShThread threads[] = new piCalcShThread[numThreads];
        
        for(int i=0;i<numThreads;i++) {
        	threads[i] = new piCalcShThread(i, sharedObj);
        	threads[i].start();
        }
        
        for(int i=0;i<numThreads;i++) {
        	try {
				threads[i].join();
			} catch (InterruptedException e) {}
        }
        

        /* end timing and print result */
        long endTime = System.currentTimeMillis();
        
        System.out.printf("Shared Object program results with %d steps\n", numSteps);
        sharedObj.printout();
        System.out.printf("time to compute = %f seconds\n", (double) (endTime - startTime) / 1000);
    }
}
