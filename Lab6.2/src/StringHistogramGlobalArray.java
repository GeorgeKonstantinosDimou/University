import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;


public class StringHistogramGlobalArray {

	static int numThreads = 8; 
	public static int[] histogram; 
	public static Lock lock = new ReentrantLock();
	
	
    public static void main(String args[]) throws IOException {

//        if (args.length != 1) {
//			System.out.println("StringHistogram <file name>");
//			System.exit(1);
//        }
        
        String fileString = new String(Files.readAllBytes(Paths.get("../Lab5-6_codes/MapReduce/world192.txt")), StandardCharsets.UTF_8);
        int n = fileString.length();
        char[] text = new char[n]; 
        for (int i = 0; i < n; i++) { 
            text[i] = fileString.charAt(i); 
        } 
        
        long start = System.currentTimeMillis();
 
        int alphabetSize = 256;
        histogram = new int[alphabetSize]; 
        for (int i = 0; i < alphabetSize; i++) { 
            histogram[i] = 0; 
        }
        
        HistogramThreadGLobalArr threads[] = new HistogramThreadGLobalArr[numThreads];
        for(int i=0;i<numThreads;i++) {
        	threads[i] = new HistogramThreadGLobalArr(i, text, n );
        	threads[i].start();
        }
        
        for(int i=0;i<numThreads;i++) {
        	try {
				threads[i].join();
			} catch (InterruptedException e) {}
        }

        for (int i = 0; i < alphabetSize; i++) { 
            System.out.println((char)i+": "+histogram[i]);
        }
        
        long elapsedTimeMillis = System.currentTimeMillis()-start;
		System.out.println("time in ms = "+ elapsedTimeMillis);
   } 
}



