import java.net.*;
import java.io.*;

public class piWorkerTCP {
	private static final String HOST = "localhost";
	private static final int PORT = 1234;
	private static final int numWorkers = 4;
	private static final long numSteps = 100000;
	
	public static void main(String args[]) throws IOException {

		Socket dataSocket = new Socket(HOST, PORT);
		
		InputStream is = dataSocket.getInputStream();
		BufferedReader in = new BufferedReader(new InputStreamReader(is));
		OutputStream os = dataSocket.getOutputStream();
		PrintWriter out = new PrintWriter(os,true);
		       	
		String inmsg, outmsg;
		WorkerProtocol app = new WorkerProtocol(numWorkers, numSteps);
		
		for(int i=0;i<numWorkers;i++) {
		inmsg = in.readLine();
		outmsg = app.compute(inmsg, i);
		out.println(outmsg);
		}
		dataSocket.close();
	}
}			

