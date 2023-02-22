//FINISHED WORK
/*
 * This program uses global variables/arrays to solve the problem
 */

public class MatVecMulTime_GlobalVar {

	static int size = 10000;
	static int n = 0;
	static double[][] a;
	static double[] x;
    static double[] y;
    
    
	public static void main(String[] args) {
		
		int numThreads = 4; 
		
		a = new double[size][size];
		
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				a[i][j] = 1;
			}	
		}
		
		x = new double[size];
		y = new double[size];
	    for(int i = 0; i < size; i++) {
			x[i] = 1;
	        y[i] = 0;
	    }
		
		Thread_GlobalVar MatVecThread[] = new Thread_GlobalVar[numThreads];
		for(int i = 0; i<numThreads; i++) {
			MatVecThread[i] = new Thread_GlobalVar(i, numThreads);
			MatVecThread[i].start();
		}
	
		for (int i = 0; i < numThreads; i++) {
            try {
            	MatVecThread[i].join();
				n = n + MatVecThread[i].threadN;
            }
            catch (InterruptedException e) {}
		}
		
		long start = System.currentTimeMillis();
		
		long elapsedTimeMillis = System.currentTimeMillis()-start;
	    System.out.println("time in ms = "+ elapsedTimeMillis);
	    
	    for(int i = 0; i < size; i++) 
	        System.out.println(y[i]);
		
	}
	
	static class Thread_GlobalVar extends Thread {

		//the thread's Id
		int threadID;
		//this is used to increment the threadID 
		int threadN;
		
		//These 2 local variables calculate where the for loop begins and ends so the 
		//thread "knows" up to which point it needs to execute
		int StartingPoint;
		int FinishPoint;
		
		public Thread_GlobalVar(int threadID, int numb) {
			this.threadID = threadID;
			this.threadN = n;
			StartingPoint = threadID * size/numb;
			FinishPoint = StartingPoint + size/numb - 1;
		}

		public void run() {	
			
			for(StartingPoint = 0; StartingPoint < FinishPoint; StartingPoint++) {
				double sum = 0;
				for(int j = 0; j < size; j++) {
					sum = sum + a[StartingPoint][j]*x[j];
				}
				 y[StartingPoint] = sum;
			}
			threadN = threadN + 1 + threadID;
		}	
	}
}
