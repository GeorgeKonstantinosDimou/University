/* 
 * This exercise is a simple toy example in the introduction of threads
 * it creates 2 different types of threads 
 */


public class Main {

	public static void main(String[] args) {
		
		int numThreads = 3;
		Thread[] threads = new Thread[numThreads];
		
		for(int i = 0; i < numThreads; i++) {
			System.out.println("In main: create and start thread " + i);
			if(i % 2 == 0) threads[i] = new MyThread1(i, numThreads);
			else threads[i] = new MyThread2(i+1, numThreads);
			threads[i].start();
		}
		
		for (int i = 0; i < numThreads; ++i) {
            try {
                threads[i].join();
            }
            catch (InterruptedException e) {
                System.err.println("this should not happen");
            }
        }
        System.out.println("In main: threads all done");
	}
}
