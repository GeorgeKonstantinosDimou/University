import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;
import java.util.HashMap;

public class WordCountHashMap {
	
	static int numThreads = 8;
	
    public static void main(String args[]) throws FileNotFoundException, IOException {
    
//        if (args.length != 1) {
//			System.out.println("WordCount  <file name>");
//			System.exit(1);
//        }
        
        String fileString = new String(Files.readAllBytes(Paths.get("../Lab5-6_codes/MapReduce/world192.txt")));//, StandardCharsets.UTF_8);
        String[] words = fileString.split("[ \n\t\r.,;:!?(){}]");    
        
        //TreeMap<String, Integer> map = new TreeMap<String, Integer>();
        HashMap<String, Integer> map = new HashMap<String, Integer>();
            
        long start = System.currentTimeMillis();
        
        int size = words.length;
        
        WordCountThreadHashMap threads[] = new WordCountThreadHashMap[numThreads];
        for(int i=0;i<numThreads;i++) {
        	threads[i] = new WordCountThreadHashMap(i, size, map, words);
        	threads[i].start();
        }
        
        for(int i=0;i<numThreads;i++) {
        	try {
				threads[i].join();
			} catch (InterruptedException e) {}
        }

        for (String name: map.keySet()) {
			String key = name.toString();
			String value = map.get(name).toString();
    		System.out.println(key + "\t " + value);
        }
        
        long elapsedTimeMillis = System.currentTimeMillis()-start;
		System.out.println("time in ms = "+ elapsedTimeMillis);
    }
}
