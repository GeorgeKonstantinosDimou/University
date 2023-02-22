/*
 * This variation of NumInt get the inspiration from the VecSumArrayMainLocal
 * it uses a local array inside the thread, calculates the result and returns
 * the whole array back in main where the final calculation is done
 */

public class piCalculationArrayMainLocal {

	static final int numThreads = 8;
	static final long numSteps = 100000000;
	
	
    public static void main(String[] args) {

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
        
        piCalcThread threads[] = new piCalcThread[numThreads];
        
        for(int i=0;i<numThreads;i++) {
        	threads[i] = new piCalcThread(i, a);
        	threads[i].start();
        }
        
        for(int i=0;i<numThreads;i++) {
        	try {
				threads[i].join();
			} catch (InterruptedException e) {}
        }
        
        double pi = 0.0;
        for (int i = 0; i < numThreads; i++) {
			//System.out.println(tsum[i]);
			pi = pi + a[i];
		}

        

        /* end timing and print result */
        long endTime = System.currentTimeMillis();
        
        System.out.printf("ArrayLocal program results with %d steps\n", numSteps);
        System.out.printf("computed pi = %22.20f\n" , pi);
        System.out.printf("difference between estimated pi and Math.PI = %22.20f\n", Math.abs(pi - Math.PI));
        System.out.printf("time to compute = %f seconds\n", (double) (endTime - startTime) / 1000);
    }
}
