
public class ThreadRegression extends Thread {
	
	private int count;
	
	public ThreadRegression(int counter) {
		this.count = counter;
	}
	
	//This thread creates another thread if count == 0. A thread can only create 1 new thread
	
	public void run() {
		if(count == 0) {
			System.out.println("Hello from thread " + Thread.currentThread().getName());
			new ThreadRegression(count);
		}
		else {
			System.out.println("This thread was created from another thread");
			System.out.println("Hello from this Thread " + Thread.currentThread().getName());
		}
			
		
		
//		if(this.marker % 2 == 0) {
//			System.out.println("Hello from thread " + Thread.currentThread().getName());
//		}
//		else {
//			System.out.println("This thread was created from another thread ");
//		}
//		if(this.marker % 2 == 1) {
//			new ThreadRegression(this.marker);
//		}
	}
}
