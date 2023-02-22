//This program prints out weird results!!
//Why is it that it prints threads with that order?


public class Main {

	public static void main(String[] args) {
		
		int numThreads = 10;
		ThreadRegression[] threads = new ThreadRegression[numThreads];
		
		for (int i = 0; i < numThreads - 1 ; ++i) {
            System.out.println("In main: create and start thread " + i);
            threads[i] = new ThreadRegression(0);
            threads[i+1] = new ThreadRegression(1);
            threads[i].start();
            threads[i+1].start();
            }
        
        /* wait for threads to finish */
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
