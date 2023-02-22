import java.net.*;
import java.io.*;

public class ServerProtocol {

	private piCalc counter;

	public ServerProtocol (piCalc c) {
		
		counter = c;
        }

	public String processRequest(String theInput) {
	 
        String theOutput;
		if (!theInput.equals("EXIT")) {
			counter.piCalculation();
			theOutput = "The value of pi for "+ theInput + " steps was found: " + counter.print();
		} else  theOutput = "EXIT";	
		return theOutput;
	}
}
