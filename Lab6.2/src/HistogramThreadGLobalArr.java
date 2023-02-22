
public class HistogramThreadGLobalArr extends Thread {

	public char[] text;
	int id;
	int n;
	int start, stop;

	public HistogramThreadGLobalArr(int id, char[] theText, int n) {
		this.id = id;
		this.n = n;
		this.text = theText;
		start = id * (n/StringHistogramGlobalArray.numThreads);
		stop = start + (n/StringHistogramGlobalArray.numThreads);
		if( id == (StringHistogramGlobalArray.numThreads-1)) stop = n;
	}
	
	public void run() {
		for (int i = start; i < stop; i++) {
			StringHistogramGlobalArray.lock.lock();
			try {
				StringHistogramGlobalArray.histogram[(int)text[i]] ++;
			} finally {
				StringHistogramGlobalArray.lock.unlock();
			}
		
		}	
	}
}