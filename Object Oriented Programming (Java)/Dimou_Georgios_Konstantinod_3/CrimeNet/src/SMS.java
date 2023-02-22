
public class SMS extends Communication {


private String message;
	
	public SMS(String Num1, String Num2, int day, int month, int year,  String message) {
		super(Num1, Num2, day, month, year);
		typeofCommunication = 1;
		this.message = message;
	}
	
	public void printInfo() {
		System.out.println("This SMS has the following info");
		super.printInfo();
		System.out.println("Text: " + message);
	}
	
	public String getMessage() {
		return message;
	}
	
}
