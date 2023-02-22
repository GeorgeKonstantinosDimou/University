import java.util.concurrent.ThreadLocalRandom;

class WriteThread extends Thread {
		
	bAccount[] account;

	public WriteThread(bAccount[] account) {
		this.account = account;
	}

	
	public void run() {
		for(int i=0;i<10;i++) {
			ThreadLocalRandom random = ThreadLocalRandom.current();
			int rn = random.nextInt(0, Bank.num);
			if(i % 2 == 0) {
				account[rn].deposit(100);
			}
			else 
				account[rn].withdraw(50);
			printout(rn);
			try {
				sleep(2000);
			} catch (InterruptedException e) {}
		}
	}
	
	public void printout(int rn) {
		System.out.println(account[rn].name +  "'s new amount: " + account[rn].balance);
	}
}