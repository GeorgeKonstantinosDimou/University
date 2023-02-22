
public class StringMatchThreadLocalArray extends Thread{

	private int start;
	private int stop;
	private int id;
	private char [] table;
	public int[] matchCou;
	private char[] pattern;
	private char[] text;
	
	
	public StringMatchThreadLocalArray(int id, char[] atable, int size, int[] matches, char[] thePattern, char[] theText) {
		this.id = id;
		this.table = atable;
		matchCou = matches;
		pattern = thePattern;
		text = theText;
		this.start = id * (size/MapReduceStringMatch.numThreads);
		this.stop = start + (size/MapReduceStringMatch.numThreads);
	}
	
	public void run() {
		 for (int j = start; j < stop; j++) {
				int i;
	      		for (i = 0; i < MapReduceStringMatch.patternString.length() && pattern[i] == text[i + j]; i++);
					if (i >= MapReduceStringMatch.patternString.length()) {
		         		table[j] = '1';
						matchCou[id]++;
	                }        
	        }
	}
	
}
