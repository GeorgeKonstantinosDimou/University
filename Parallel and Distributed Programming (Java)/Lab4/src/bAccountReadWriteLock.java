import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class bAccountReadWriteLock {

	int balance;
	String name;
	private final ReadWriteLock lock = new ReentrantReadWriteLock(); 

	public bAccountReadWriteLock(String aName, int balance) {
		this.balance = balance;
		this.name = aName;
	}
	
	public int getBalance() {
		lock.readLock().lock();
		try {
		return this.balance;
		} finally {
			lock.readLock().unlock();
		}
	}
	
	public void deposit(int numb) {
		lock.writeLock().lock();
	    try {
	      balance += numb;
	    } finally {
	      lock.writeLock().unlock();
	    }
	}
	
	public void withdraw(int numb) {
		lock.writeLock().lock();
	    try {
	      balance -= numb;
	    } finally {
	      lock.writeLock().unlock();
	    }
	}
	
}
