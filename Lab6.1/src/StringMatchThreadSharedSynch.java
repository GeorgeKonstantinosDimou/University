public class StringMatchThreadSharedSynch extends Thread{

	private int start;
	private int stop;
	private int id;
	SharedObjSynch sharedObj;
	
	
	
	public StringMatchThreadSharedSynch(int id, SharedObjSynch aSharedObj) {
		this.id = id;
		sharedObj = aSharedObj;
		this.start = id * (sharedObj.matchLength/MapReduceStringMatchSharedObjSynch.numThreads);
		this.stop = start + (sharedObj.matchLength/MapReduceStringMatchSharedObjSynch.numThreads);
	}
	
	public void run() {
		 for (int j = start; j < stop; j++) {
				int i;
	      		for (i = 0; i < sharedObj.patternString.length() && sharedObj.pattern[i] == sharedObj.text[i + j]; i++);
						if (i >= sharedObj.patternString.length()) {
							sharedObj.add(j);
						}
					
	            }
		 }	
}