
public class piCalcThreadGlobalLock extends Thread {
	
	long start;
	long stop;
	int id;
	private double mySum;
	
	public piCalcThreadGlobalLock(int id) {
		this.id = id;
		mySum = 0.0;
		start = id * (piCalculationGlobalLock.numSteps / piCalculationGlobalLock.numThreads);
		stop = start + (piCalculationGlobalLock.numSteps / piCalculationGlobalLock.numThreads);
		if(id == (piCalculationGlobalLock.numThreads - 1)) stop = piCalculationGlobalLock.numSteps;
	}
	
	
	public void run() {
			double step = 1.0 / (double)piCalculationGlobalLock.numSteps;
	        /* do computation */
			piCalculationGlobalLock.lock.lock();
			try {
	        for (long i=start; i < stop; ++i) {
	            double x = ((double)i+0.5)*step;
	            mySum += 4.0/(1.0+x*x);
	        }
	        piCalculationGlobalLock.pi = piCalculationGlobalLock.pi + mySum * step;
			} finally {
				piCalculationGlobalLock.lock.unlock();
			}
	}
	
}
