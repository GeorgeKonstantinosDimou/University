//FINISHED WORK

/*Here with the help of reference Values i solve the same problem without arrays
 * by passing values through the thread constructor and then returning them 
 */

public class MatVecMulTime_ValueArgument {
    
	public static void main(String[] args) {
		
		int numThreads = 4; 
		int size = 100;
			
	    int n = 0;
		Thread_GlobalVar MatVecThread[] = new Thread_GlobalVar[numThreads];
		for(int i = 0; i<numThreads; i++) {
			MatVecThread[i] = new Thread_GlobalVar(i, size, numThreads, n);
			MatVecThread[i].start();
		}
		
		
		for (int i = 0; i < numThreads; i++) {
            try {
            	MatVecThread[i].join();
				n = n + MatVecThread[i].threadN;
            }
            catch (InterruptedException e) {}
		}
	        System.out.println("Main n = " + n);
	}
	
	static class Thread_GlobalVar extends Thread {

		//the thread's Id
		int threadID;
		//this is used to increment the threadID 
		int threadN;
		int Size;
		
		//These 2 local variables calculate where the for loop begins and ends so the 
		//thread "knows" up to which point it needs to execute
		int StartingPoint;
		int FinishPoint;
		
		public Thread_GlobalVar(int threadID, int size, int numb, int n) {
			this.threadID = threadID;
			this.Size = size;
			this.threadN = n;
			StartingPoint = threadID * size/numb;
			FinishPoint = StartingPoint + size/numb - 1;
		}

		public void run() {	
			
			for(StartingPoint = 0; StartingPoint < FinishPoint; StartingPoint++) {
				double tempSum = 0;
				for(int j = 0; j < Size; j++) {
					tempSum = tempSum + 1 * 1;
				}
				double Sum = tempSum;
				threadN = threadN + 1 + threadID;
				System.out.println("Thread " + threadID + " n = " + Sum);
			}
		}	
	}
}
