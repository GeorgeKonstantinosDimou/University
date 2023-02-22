/*
 * In this program every variable is a local variable, as it doesnt contain any form 
 * of parallism
 * All it does is simply calculate a sum (which always equals to 1000) and puts it in the 
 * y array 
 */


public class MatVecMulTime {

	public static void main(String[] args) {
		
		int size = 1000;
		
		double[][] a = new double[size][size];
	    for(int i = 0; i < size; i++)
	    	for(int j = 0; j < size; j++)
			    a[i][j] = 1;
	    
	    double[] x = new double[size];
	    double[] y = new double[size];
	    for(int i = 0; i < size; i++) {
			x[i] = 1;
	        y[i] = 0;
	    }
	    
	    //local variable 
	    long start = System.currentTimeMillis();
			
	    for (int i= 0; i < size; i++) {
	        double sum = 0;
	        for (int j = 0; j < size; j++) {
	            sum = sum + a[i][j]*x[j];
	        }
	        y[i] = sum;
	    }

	    long elapsedTimeMillis = System.currentTimeMillis()-start;
	    System.out.println("time in ms = "+ elapsedTimeMillis);
	    
	    for(int i = 0; i < size; i++) 
	        System.out.println(y[i]); 
	}

}
