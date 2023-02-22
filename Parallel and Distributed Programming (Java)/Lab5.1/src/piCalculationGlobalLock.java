import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/*
 * This variation of NumInt get the inspiration from the VecSumGlobalLock
 * it uses a global ReentrantLock and does the calculations inside 
 */

public class piCalculationGlobalLock {

	static final int numThreads = 8;
	static final long numSteps = 100000000;
	public static Lock lock = new ReentrantLock();
	public static double pi;
	
	
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
        
        piCalcThreadGlobalLock threads[] = new piCalcThreadGlobalLock[numThreads];
        
        for(int i=0;i<numThreads;i++) {
        	threads[i] = new piCalcThreadGlobalLock(i);
        	threads[i].start();
        }
        
        for(int i=0;i<numThreads;i++) {
        	try {
				threads[i].join();
			} catch (InterruptedException e) {}
        }
       
        /* end timing and print result */
        long endTime = System.currentTimeMillis();
        
        System.out.printf("Global Lock program results with %d steps\n", numSteps);
        System.out.printf("computed pi = %22.20f\n" , pi);
        System.out.printf("difference between estimated pi and Math.PI = %22.20f\n", Math.abs(pi - Math.PI));
        System.out.printf("time to compute = %f seconds\n", (double) (endTime - startTime) / 1000);
    }
}
