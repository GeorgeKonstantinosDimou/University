import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class StringMatchThreadLock extends Thread{

	private int start;
	private int stop;
	private int id;
	private char [] table;
	public int[] matchCou;
	private char[] pattern;
	private char[] text;
	
	
	
	public StringMatchThreadLock(int id, char[] atable, int size, int[] matches, char[] thePattern, char[] theText) {
		this.id = id;
		this.table = atable;
		matchCou = matches;
		pattern = thePattern;
		text = theText;
		this.start = id * (size/MapReduceStringMatchLock.numThreads);
		this.stop = start + (size/MapReduceStringMatchLock.numThreads);
	}
	
	public void run() {
		 for (int j = start; j < stop; j++) {
				int i;
	      		for (i = 0; i < MapReduceStringMatchLock.patternString.length() && pattern[i] == text[i + j]; i++);
	      			MapReduceStringMatchLock.lock.lock();
					try { 
						if (i >= MapReduceStringMatchLock.patternString.length()) {
							table[j] = '1';
							MapReduceStringMatchLock.matchCounter++;
						}
					} finally {
						MapReduceStringMatchLock.lock.unlock();
						//matchCou[id]++;
					}
	            }
		 }	
}