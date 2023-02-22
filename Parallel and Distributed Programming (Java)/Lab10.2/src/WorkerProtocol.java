import java.net.*;
import java.io.*;

public class WorkerProtocol {

	private int numWorkers;
	private long numSteps;
	
	public WorkerProtocol(int num, long theSteps) {
		numWorkers = num;
		numSteps = theSteps;
	}	

	public String compute(String theInput, int id) throws IOException {
	
		int range = Integer.parseInt(theInput); 
		
		System.out.println("Worker "+ id +" calculates");
		
		int block = range / numWorkers;
		int start = id * block;
		int stop = start + block;
		if (id == numWorkers-1) stop = range;
		
		double sum = 0.0;
		
		 double step = 1.0 / (double)numSteps;
        /* do computation */
        for (long i=start; i < stop; ++i) {
            double x = ((double)i+0.5)*step;
            sum += 4.0/(1.0+x*x);
        }
        double pi = sum * step;
			
		String theOutput = String.valueOf(pi);	
		return theOutput;
	}
}
