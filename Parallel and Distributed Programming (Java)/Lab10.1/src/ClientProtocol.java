import java.net.*;
import java.io.*;

public class ClientProtocol {
	
	BufferedReader user = new BufferedReader(new InputStreamReader(System.in));
	
	public String prepareRequest() throws IOException {
	
		System.out.print("Enter how many iterations you want to do to calc pi:");
		String theOutput = user.readLine();
		return theOutput;
	}
        
	public String prepareExit() throws IOException {
	
		String theOutput = "EXIT";
		return theOutput;
	}

	public void processReply(String theInput) throws IOException {
	
		System.out.println("Reply: " + theInput);
	}
}
