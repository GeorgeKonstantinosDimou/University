public class bAccount {

	int balance;
	String name;
	

	public bAccount(String aName, int balance) {
		this.balance = balance;
		this.name = aName;
	}
	
	public int getBalance() {
		return this.balance;
	}
	
	public void deposit(int numb) {
		balance += numb;
	}
	
	public void withdraw(int numb) {
		balance -= numb;
	}
	
}
