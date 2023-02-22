
public class piCalcThread extends Thread {

	private double [] table;
	long start;
	long stop;
	int id;
	private double mySum;
	
	public piCalcThread(int id, double ts[]) {
		this.id = id;
		this.table = ts;
		mySum = 0.0;
		start = id * (piCalculationArrayMainLocal.numSteps / piCalculationArrayMainLocal.numThreads);
		stop = start + (piCalculationArrayMainLocal.numSteps / piCalculationArrayMainLocal.numThreads);
		if(id == (piCalculationArrayMainLocal.numThreads - 1)) stop = piCalculationArrayMainLocal.numSteps;
	}
	
	
	public void run() {
			double step = 1.0 / (double)piCalculationArrayMainLocal.numSteps;
	        /* do computation */
	        for (long i=start; i < stop; ++i) {
	            double x = ((double)i+0.5)*step;
	            mySum += 4.0/(1.0+x*x);
	        }
	        table[id] = mySum * step;
	}
	
}
