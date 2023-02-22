
public class piCalcShThread extends Thread {

	private piCalcObj shared;
	long start;
	long stop;
	int id;
	
	public piCalcShThread(int id, piCalcObj s) {
		this.id = id;
		this.shared = s;
		start = id * (piCalculationArrayMainLocal.numSteps / piCalculationArrayMainLocal.numThreads);
		stop = start + (piCalculationArrayMainLocal.numSteps / piCalculationArrayMainLocal.numThreads);
		if(id == (piCalculationArrayMainLocal.numThreads - 1)) stop = piCalculationArrayMainLocal.numSteps;
	}
	
	
	public void run() {
			double step = 1.0 / (double)piCalculationArrayMainLocal.numSteps;
	           shared.add(step, start, stop);
	        }
}
