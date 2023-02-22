
public class ThreadSieveExecutor implements Runnable {

	private int id;
	private int blockSize;
	private int limit;
	private boolean[] prime;
	
	
	public ThreadSieveExecutor(int id, int blockSize, int tableSize, boolean[] prime) {
		this.id = id;
		this.blockSize = blockSize;
		this.limit = tableSize;
		this.prime = prime;
	}


	public void run() {
		
		int myfrom = 0;
		int myto = 0;
		
		myfrom = id * blockSize;
		myto = myfrom + blockSize;
		if(myto > limit) myto = limit;
		if(id == 0) myfrom = 2;
		
		for (int p = myfrom; p <= myto; p++)
		{
			// If prime[p] is not changed, then it is a prime
			if(prime[p] == true)
			{
				// Update all multiples of p
				for (int i = p*p; i <= SieveExecutor.size; i += p)
					prime[i] = false;
			}
		}
		
	}

}
