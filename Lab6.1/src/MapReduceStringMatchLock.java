import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock; 


/*
 * This program uses a simple ReentrantLock to accomplish its purposes
 * while making the matchCounter variable global. It is a lot slower though
 */

public class MapReduceStringMatchLock {

	static int numThreads = 8;
	static String patternString = new String("Exclusive economic zone");
	public static Lock lock = new ReentrantLock();
	static int matchCounter = 0;
	
    public static void main(String args[]) throws IOException {
    
//        if (args.length != 2) {
//			System.out.println("BruteForceStringMatch  <file name> <pattern>");
//			System.exit(1);
//        }
    	
    	long start = System.currentTimeMillis();

        String fileString = new String(Files.readAllBytes(Paths.get("../Lab5-6_codes/MapReduce/world192.txt")));//, StandardCharsets.UTF_8);
        char[] text = new char[fileString.length()]; 
        int n = fileString.length();
        for (int i = 0; i < n; i++) { 
            text[i] = fileString.charAt(i); 
        } 
 
                                                        
        char[] pattern = new char[patternString.length()]; 
        int m = patternString.length(); 
        for (int i = 0; i < m; i++) { 
            pattern[i] = patternString.charAt(i); 
        }

        int matchLength = n - m;
        char[] match = new char[matchLength+1]; 
        for (int i = 0; i <= matchLength; i++) { 
            match[i] = '0'; 
        }
        
        /*ArrayList<Integer> match = new ArrayList<Integer>(); */
        int[] matchCount = new int[numThreads];
        for(int i=0;i<numThreads;i++) {
        	matchCount[i] = 0;
        }
        
        StringMatchThreadLock[] threads = new StringMatchThreadLock[numThreads];
        for(int i=0;i<numThreads;i++) {
        	threads[i] = new StringMatchThreadLock(i, match, matchLength, matchCount, pattern, text);
        	threads[i].start();
        }
        
        for(int i=0;i<numThreads;i++) {
        	try {
				threads[i].join();
			} catch (InterruptedException e) {}
        }
       
       //use the thread local array to calculate the matches
       
//        for(int i=0;i<numThreads;i++) {
//        	matchCounter = matchCounter + matchCount[i];
//        }
       


        for (int i = 0; i < matchLength; i++) { 
            if (match[i] == '1') System.out.print(i+" ");
        }
        System.out.println();
        System.out.println("Total matches " + matchCounter);
        
        long elapsedTimeMillis = System.currentTimeMillis()-start;
		System.out.println("time in ms = "+ elapsedTimeMillis);
        
   }
}



