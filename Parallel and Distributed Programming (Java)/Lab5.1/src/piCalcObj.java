
public class piCalcObj {

	public double pi;
	public double sum;
	
	public piCalcObj() {
		pi = 0.0;
		sum = 0.0;
	}
	
	public synchronized void add(double astep, long start, long stop) {
		for (long i=start; i < stop; ++i) {
            double x = ((double)i+0.5)*astep;
            sum += 4.0/(1.0+x*x);
		}
		pi = sum * astep;
	}
	
	public synchronized void printout() {
		System.out.printf("computed pi = %22.20f\n" , pi);
		System.out.printf("difference between estimated pi and Math.PI = %22.20f\n", Math.abs(pi - Math.PI));
	}
	
}
