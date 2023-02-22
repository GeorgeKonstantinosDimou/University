
public class HistogramThreadLocalArr extends Thread {

	public int[] histogram;
	public char[] text;
	int id;
	int n;
	int start, stop;

	public HistogramThreadLocalArr(int id, int[] theHistogram, char[] theText, int n) {
		this.id = id;
		this.n = n;
		this.histogram = theHistogram;
		this.text = theText;
		start = id * (n/StringHistogramLocalArrayThread.numThreads);
		stop = start + (n/StringHistogramLocalArrayThread.numThreads);
		if( id == (StringHistogramLocalArrayThread.numThreads-1)) stop = n;
	}
	
	public void run() {
		for (int i = start; i < stop; i++) {
			histogram[(int)text[i]] ++;			
        }
	}
	
}
