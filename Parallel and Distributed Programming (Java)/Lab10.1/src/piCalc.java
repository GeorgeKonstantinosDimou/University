public class piCalc {
	private long numSteps;
	private double sum;
	private double pi;
	
	public piCalc (long theSteps) {
		numSteps = theSteps;
		sum = 0.0;
		pi = 0.0;
	}
	
	public piCalc () {
		numSteps = 1000000;
		sum = 0.0;
		pi = 0.0;
	}

	public synchronized void piCalculation() {
		pi = 0.0;
		sum = 0.0;
		double step = 1.0/(double)numSteps;
		for (long i=0; i < numSteps; ++i) {
            double x = ((double)i+0.5)*step;
            sum += 4.0/(1.0+x*x);
        }
        pi = sum * step;
        }

        public synchronized String print () {
		    return String.valueOf(pi);
        }
}
