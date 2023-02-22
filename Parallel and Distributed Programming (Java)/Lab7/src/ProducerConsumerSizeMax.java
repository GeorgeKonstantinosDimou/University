public class ProducerConsumerSizeMax
{
	public static void main()
	{
		//int bufferSize = 5;
		int noIterations = 20;
		int producerDelay = 100;
		int consumerDelay = 1;
		int noProds = 3;
		int noCons = 2;
		Producer prod[] = new Producer[noProds];
		Consumer cons[] = new Consumer[noCons];
		

		// Bounded Buffer
		BufferSizeMax buff = new BufferSizeMax();
		
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