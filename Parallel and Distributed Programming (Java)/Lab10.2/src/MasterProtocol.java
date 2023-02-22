import java.net.*;
import java.io.*;

public class MasterProtocol {

	private piSharedObj myPi;
	private int myId;

	public MasterProtocol (piSharedObj s, int id) {
		
		myPi = s;
		myId = id;
	}

	public String prepareRequest() {
	 
		//String theOutput = myPi.printInit() + " " + String.valueOf(myId);
		String theOutput = String.valueOf(myId);
		return theOutput;
	}
	
	public void processReply(String theInput) {
	
		int repl = Integer.parseInt(theInput);
		myPi.calculatePi(repl);
	}	
}
