class SieveCyclic {
	
	static int size = 100000000;
	
	public static void main(String[] args)
	{  
		
		
		int numThreads = 0;
//		if (args.length != 1) {
//			System.out.println("Usage: java SieveOfEratosthenes <size>");
//			System.exit(1);
//		}
//
//		try {
//			size = Integer.parseInt(args[0]);
//		}
//		catch (NumberFormatException nfe) {
//	   		System.out.println("Integer argument expected");
//    		System.exit(1);
//		}
//		if (size <= 0) {
//				System.out.println("size should be positive integer");
//	    		System.exit(1);
//		}
		if(numThreads == 0) numThreads = Runtime.getRuntime().availableProcessors();
		
		boolean[] prime = new boolean[size+1];

		for(int i = 0; i < size+1; i++)
			prime[i] = true; 		

		// get current time 
		long start = System.currentTimeMillis();
		
		int limit = (int)Math.sqrt(size) + 1;
		
		ThreadSieveCyclic threads[] = new ThreadSieveCyclic[numThreads];
		for(int i=0;i<numThreads;i++) {
			threads[i] = new ThreadSieveCyclic(i, limit, numThreads, prime);
			threads[i].start();
		}
		
		for(int i=0;i<numThreads;i++) {
			try {
				threads[i].join();
			} catch (InterruptedException e) {}
		}
		
		//for (int p = 2; p*p <= size; p++)
		int count = 0;
		for(int i = 0; i < size+1; i++) 
			if (prime[i] == true) {
				//System.out.println(i); 
				count++;
			}
               
		// get current time and calculate elapsed time
		long elapsedTimeMillis = System.currentTimeMillis()-start;
				
		System.out.println("number of primes "+count); 
		System.out.println("time in ms = "+ elapsedTimeMillis);
	}

}
