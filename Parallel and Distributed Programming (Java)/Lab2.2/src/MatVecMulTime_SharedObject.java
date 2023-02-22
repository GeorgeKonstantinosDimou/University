//Finished


public class MatVecMulTime_SharedObject {

	public static void main(String[] args) {
	    
		int numThreads = 4; 
		
	    
		SharedCounter count = new SharedCounter();
		
	    Thread_SharedObj MatVecThread[] = new Thread_SharedObj[numThreads];
		for(int i = 0; i<numThreads; i++) {
			MatVecThread[i] = new Thread_SharedObj(i, numThreads);
			MatVecThread[i].start();
		}
		
		 for (int i = 0; i < numThreads; i++) {
	            try {
	            	MatVecThread[i].join();
					count.n = count.n + MatVecThread[i].threadN;
	            }
	            catch (InterruptedException e) {}
		 }
	   
	    for (int i = 0; i < count.size; i++)
			System.out.println("y["+i+"] = "+count.y[i]);
			
		System.out.println("n = "+ count.n); 
	}	
	
	/*
	 * In this object i store every array/variable which normally would need to be shared
	 * with the thread class
	 * There are the 3 arrays which are needed for the operations. A n variable
	 * which is used to define the thread 
	 */
	
	static class SharedCounter {
		
		static double[][] a; 
		static double[] x;
		static double[] y;
		static int n;
		
		static int size = 100;
		
		
		public SharedCounter () {

			this.n = 0;
			this.a = new double[size][size];
			this.x = new double[size];
			this.y = new double[size];
			
			for(int i = 0; i < size; i++) {
				x[i] = 1;
				y[i] = 0;
				for(int y = 0; y < size; y++) {
					a[i][y] = 1;
				}
			}
			
		}
	}
	
	
	
	static class Thread_SharedObj extends Thread {
		
		//the thread's Id
		int threadID;
		//this is used to increment the threadID
		int threadN;
		
		SharedCounter threadCount;
		
		//These 2 local variables calculate where the for loop begins and ends so the 
		//thread "knows" up to which point it needs to execute
		int StartingPoint;	
		int FinishPoint;
		
		public Thread_SharedObj(int threadID, int numbofThreads) {
			this.threadID = threadID;
			this.threadN = threadCount.n;
			StartingPoint = threadID * threadCount.size/numbofThreads;
			FinishPoint = StartingPoint + threadCount.size/numbofThreads - 1;
		}
		
		public void run() {	
			
			for(StartingPoint = 0; StartingPoint < FinishPoint; StartingPoint++) {
				double sum = 0;
				for(int j = 0; j < threadCount.size; j++) {
					sum = sum + threadCount.a[StartingPoint][j] * threadCount.x[j];
				}
				 threadCount.y[StartingPoint] = sum;
				 threadCount.n = threadCount.n + 1 + threadID;
				 System.out.println("Thread "+threadID+" n = "+ threadCount.n +"  y["+threadID+"] ="+ threadCount.y[threadID]);
			}
		}	
	}	
}

