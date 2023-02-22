import java.util.concurrent.ThreadLocalRandom;

class ReadThread extends Thread {
		
		bAccount[] account;

		public ReadThread(bAccount[] account) {
			this.account = account;
		}

		
		public void run() {
			for(int i=0;i<1000;i++) {
				printout();
				try {
					sleep(5);
				} catch (InterruptedException e) {}
			}
		}
		
		public void printout() {
			ThreadLocalRandom random = ThreadLocalRandom.current();
			System.out.println(account[random.nextInt(0, Bank.num)].name + "'s balance is: " +  account[random.nextInt(0, Bank.num)].getBalance());
		}
		
//		void RandomDelay() {
//	        int scale = 1000;
//	        try {
//	            sleep((int)(Math.random()*scale));
//	        } catch (InterruptedException e) { }
//	    }
		
	}