public class Bank {
 
	static int num = 3;
	
	public static void main (String[] args) {
		
		bAccount accounts[] = new bAccount[num];
		
		accounts[0] = new bAccount ("John", 200);
		accounts[1] = new bAccount ("Mary", 300);
		accounts[2] = new bAccount ("George", 400);
		
		long start = System.currentTimeMillis();
		
		ReadThread threadR1 = new ReadThread(accounts);
		ReadThread threadR2 = new ReadThread(accounts);
		WriteThread threadW1 = new WriteThread(accounts);
		
		threadR1.start();
		threadR2.start();
		threadW1.start();
		
		try {
			threadR1.join();
			threadR2.join();
			threadW1.join();
		} catch (InterruptedException e) {}		
		
		long elapsedTimeMillis = System.currentTimeMillis()-start;
		System.out.println("time in ms = "+ elapsedTimeMillis);
		
	}
}	 
