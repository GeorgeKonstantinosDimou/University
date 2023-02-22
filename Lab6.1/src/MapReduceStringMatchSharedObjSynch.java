import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

/*
 * This program uses a simple ReentrantLock to accomplish its purposes
 * while making the matchCounter variable global. It is a lot slower though
 */

public class MapReduceStringMatchSharedObjSynch {

	static int numThreads = 12;
	
    public static void main(String args[]) throws IOException {
    
//        if (args.length != 2) {
//			System.out.println("BruteForceStringMatch  <file name> <pattern>");
//			System.exit(1);
//        }
    	
    	long start = System.currentTimeMillis();

        String fileString = new String(Files.readAllBytes(Paths.get("../Lab5-6_codes/MapReduce/world192.txt")));//, StandardCharsets.UTF_8);
        
        SharedObjSynch sharedObj = new SharedObjSynch(fileString);  
        
        StringMatchThreadSharedSynch[] threads = new StringMatchThreadSharedSynch[numThreads];
        for(int i=0;i<numThreads;i++) {
        	threads[i] = new StringMatchThreadSharedSynch(i, sharedObj);
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
       


        for (int i = 0; i < sharedObj.matchLength; i++) { 
            if (sharedObj.match[i] == '1') System.out.print(i+" ");
        }
        System.out.println();
        System.out.println("Total matches " + sharedObj.matchCounter);
        
        long elapsedTimeMillis = System.currentTimeMillis()-start;
		System.out.println("time in ms = "+ elapsedTimeMillis);
        
   }
}



