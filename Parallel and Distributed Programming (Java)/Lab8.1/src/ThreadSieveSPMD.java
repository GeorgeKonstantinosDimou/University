
public class ThreadSieveSPMD extends Thread {
	
	private int start;
	private int stop;
	private int id;
	//private int size;
	private int numThreads;
	boolean[] prime;
	
	public ThreadSieveSPMD(int theID, int size, int numofThreads, boolean[] isPrime) {
		this.id = theID;
		this.prime = isPrime;
		numThreads = numofThreads;
		start = id * (size/numThreads);
		if(id == 0) start = 2;
		stop = start + (size/numThreads);
		if(id == numThreads - 1) stop = size;
	}
	
	public void run() {
		for (int p = start; p <= stop; p++)
		{
			// If prime[p] is not changed, then it is a prime
			if(prime[p] == true)
			{
				// Update all multiples of p
				for (int i = p*p; i <= SieveSPMD.size; i += p)
					prime[i] = false;
			}
		}
	}

}
