import java.util.concurrent.locks.ReentrantLock;
/*
 * Αδρομερές κλείδωμα ολόκληρου του πίνακα
 */
public class bAccountLockArray {

	int balance;
	String name;
	private ReentrantLock lock = new ReentrantLock();
	

	public bAccountLockArray(String aName, int balance) {
		this.balance = balance;
		this.name = aName;
	}
	
	public int getBalance() {
		lock.lock();
	    try {
	      return balance;
	    } finally {
	      lock.unlock();
	    }
	}
	
	public void deposit(int numb) {
		lock.lock();
	    try {
	      balance += numb;
	    } finally {
	      lock.unlock();
	    }
	}
	
	public void withdraw(int numb) {
		lock.lock();
	    try {
	      balance -= numb;
	    } finally {
	      lock.unlock();
	    }
	}
	
}
