import java.util.concurrent.*;

public class NumIntForkJoin {

	public static final int ARRAY_SIZE = 10000000;
    public static double[] numberArray = new double[ARRAY_SIZE];
    public static final double step = 1.0 / (double)ARRAY_SIZE;
	
	//a method for the creation of the sum Vector and later on
	//its sum on a single Variable
	
	private static double sumVectorUsingForkJoin() {
	    double total = 0.0;
	    ForkJoinPool pool = new ForkJoinPool(); // create thread pool for fork/join
	    NumIntForkSumVectorTask task = new NumIntForkSumVectorTask( 0, ARRAY_SIZE);
	    total = pool.invoke(task); // submit the task to fork/join pool
	    pool.shutdown();
	    return total;
	  }
	
	
	
    public static void main(String[] args) {

    	
    	//steps here is the global attribute ARRAY_SIZE
        double sum = 0.0;
        
        /* start timing */
        long startTime = System.currentTimeMillis();

        

        double count = sumVectorUsingForkJoin();
        double pi = count * step;
        
        /* end timing and print result */
        long endTime = System.currentTimeMillis();
        
        System.out.printf("ForkJoin program results with %d steps\n", ARRAY_SIZE);
        System.out.printf("computed pi = %22.20f\n" , pi);
        System.out.printf("difference between estimated pi and Math.PI = %22.20f\n", Math.abs(pi - Math.PI));
        System.out.printf("time to compute = %f seconds\n", (double) (endTime - startTime) / 1000);
    }
}
