class Philosopher_fixed extends Thread {
  private int identity;
  private Fork_fixed left;
  private Fork_fixed right;
  private int scale;
  private int next;

  Philosopher_fixed(int id, int n, int s, Fork_fixed l, Fork_fixed r) {
    	identity = id; next = n; scale = s; left = l; right = r; 
  }

  public void run() {
     while (true) {
        //thinking
		System.out.println(" Philosopher "+ identity + " is thinking");
        delay(scale);
        //hungry
        System.out.println(" Philosopher "+ identity+ " is trying to get fork " + identity);
        if(identity % 2 == 0) {
        	left.get();
        }
        else {
        	right.get();
        }
        
        //gotright chopstick
        System.out.println(" Philosopher "+ identity+ " got fork " + identity + " and is trying to get fork " + next);
        if(identity % 2 == 0) {	
        	right.get();
        }
        else {
        	left.get();
        }
        System.out.println(" Philosopher "+ identity + " is eating");
        //eating
        System.out.println(" Philosopher "+ identity + " is releasing left fork " + next);
        //delay(scale);
        left.put();
		System.out.println(" Philosopher "+ identity + " is releasing fork " + identity);
		//delay(scale);
        right.put();
        break;
     }    
  }

  public void delay(int scale) {
	try {
		 sleep((int)(Math.random()*scale));
	} catch (InterruptedException e) { }
  }
}
