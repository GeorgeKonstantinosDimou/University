
public class PhoneCall extends Communication {
	
	private int callDuration;
	
	public PhoneCall(String Num1, String Num2, int day, int month, int year, int callDuration) {
		super(Num1, Num2, day, month, year);
		typeofCommunication = 0;
		this.callDuration = callDuration;
	}
	
	public void printInfo() {
		System.out.println("This phone call has the following info");
		super.printInfo();
		System.out.println("Duration: " + callDuration);
	}
	
	public int getCallDuration() {
		return callDuration;
	}
	
}
