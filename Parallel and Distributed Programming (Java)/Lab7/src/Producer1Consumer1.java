/*
 * Just change the Producer/Consumer to the correct type
 */

public class Producer1Consumer1
{
	public static void main(String[] args)
	{
		int bufferSize = 5;
		int noIterations = 20;
		int producerDelay = 100;
		int consumerDelay = 1;
		int noProds = 1;
		int noCons = 1;
		Producer prod[] = new Producer[noProds];
		Consumer cons[] = new Consumer[noCons];
		

		// Bounded Buffer
		BufferFor1 buff = new BufferFor1(bufferSize);
		
		// Producer threads
		for (int i=0; i<noProds; i++) {
			prod[i] = new Producer(buff, noIterations, producerDelay);
			prod[i].start();
		}

		// Consumer threads
		for (int j=0; j<noCons; j++) {
	        cons[j] = new Consumer(buff, consumerDelay);
			cons[j].start();
		}
		
//		for (int i=0; i<noProds; i++) {
//			try {
//				prod[i].join();
//			} catch (InterruptedException e) {}
//		}
//		
//		for (int j=0; j<noCons; j++) {
//			try {
//				cons[j].join();
//			} catch (InterruptedException e) {}
//		}
		
	}
}