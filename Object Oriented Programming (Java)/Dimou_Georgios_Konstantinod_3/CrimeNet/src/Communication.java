//abstract class Communication 
//there can never be just a Communication object,only a PhoneCall/SMS 
//it serves  just as a "database" for the subclasses {PhoneCall,SMS}
public abstract class Communication {

	
	protected String Num1, Num2;
	protected int day, month, year;
	//an attribute which helps define the type of the Communication 
	//in this iteration takes only 0 for PhoneCall and 1 for SMS
	protected int typeofCommunication;
	
	public Communication(String Num1, String Num2, int day, int month, int year) {
		this.Num1 = Num1;
		this.Num2 = Num2;
		this.day = day;
		this.month = month;
		this.year = year;
	}
	
	public void printInfo() {
		System.out.println("Between " + Num1 + " --- " + Num2);
		System.out.println("on " + year +"/" + month +"/" + day);
	}
	
	public String getNum1() {
		return Num1;
	}

	public String getNum2() {
		return Num2;
	}	
}
	
