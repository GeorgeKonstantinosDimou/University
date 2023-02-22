
public class ThreadSieveCyclic extends Thread{

	private int myrank;
	private int numThreads;
	private boolean[] prime;
	private int limit;
	private int start;
	
	public ThreadSieveCyclic(int id, int theLimit, int numThreads, boolean[] isPrime) {
		limit = theLimit;
		this.myrank = id;
		this.numThreads = numThreads;
		prime = isPrime;
		start = myrank + 2; 
	}
	
	public void run() {
		for(int p=start;p<=limit;p+=numThreads) {
			{
				// If prime[p] is not changed, then it is a prime
				if(prime[p] == true)
				{
					// Update all multiples of p
					for (int i = p*p; i <= SieveCyclic.size; i += p)
						prime[i] = false;
				}
			}
		}
	}
	
}
