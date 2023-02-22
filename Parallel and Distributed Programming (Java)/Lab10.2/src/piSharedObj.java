public class piSharedObj {
	private static int anum;
	private static int result;
	
	public piSharedObj () {
		result = 0;
	}

	public synchronized void calculatePi(int toAdd) {
		result += toAdd;
	}

	public synchronized void printResult () {
	    System.out.println("Result =" + result);
	}
	
//	public synchronized String printInit () {
//	    return String.valueOf(anum);
//	}
        
}
