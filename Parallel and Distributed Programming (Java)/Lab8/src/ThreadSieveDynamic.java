
public class ThreadSieveDynamic implements Runnable{

	private int id;
	private boolean[] prime;
	
	
	public ThreadSieveDynamic(int myID, boolean[] thePrimes) {
		this.id = myID;
		prime = thePrimes;
	}


	public void run() {
		int element;
		while((element = SieveDynamic.getTask()) >= 0) {
			//System.out.println("worker " + id + " received " + element);
				// If prime[p] is not changed, then it is a prime
				if(prime[element] == true) {
					// Update all multiples of p
					for (int i = element * element; i <= SieveDynamic.size; i += element)
						prime[i] = false;
				}
		}
	}
}
