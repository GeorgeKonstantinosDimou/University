import java.util.TreeMap;

public class WordCountThreadTreeMap extends Thread{

	private int id;
	private int start;
	private int stop;
	private String[] words;
	private TreeMap<String, Integer> map;
	
	
	public WordCountThreadTreeMap(int id, int size, TreeMap theMap, String[] theWords) {
		this.id = id;
		map = theMap;
		words = theWords;
		this.start = id * (size/WordCountTreeMap.numThreads);
		this.stop = start + (size/WordCountTreeMap.numThreads);
		if(id == WordCountTreeMap.numThreads - 1) stop = size;
	}
	
	public void run() {
		for (int wordCounter = start; wordCounter < stop; wordCounter++) {
            String key = words[wordCounter].toLowerCase();
            if (key.length() > 0) {
                if (map.get(key) == null) {
                    map.put(key, 1);
                }
                else {
                	int value = map.get(key).intValue();
                	value++;
                	map.put(key, value);
                }
            }
        }
	}
	
}
