
public class SharedObjSynch {

	public String patternString = new String("Exclusive economic zone");
	public String fileString;
	public char[] text;
	public char[] pattern;
	public int matchLength;
	public char[] match;
	public int matchCounter;
	
	public SharedObjSynch(String filePath) {
		this.fileString = filePath;
		text = new char[fileString.length()]; 
        int n = fileString.length();
        for (int i = 0; i < n; i++) { 
            text[i] = fileString.charAt(i); 
        }
        
        pattern = new char[patternString.length()]; 
        int m = patternString.length(); 
        for (int i = 0; i < m; i++) { 
            pattern[i] = patternString.charAt(i); 
        }
        
        matchLength = n - m;
        match = new char[matchLength+1]; 
        for (int i = 0; i <= matchLength; i++) { 
            match[i] = '0'; 
        }
	}
	
	public synchronized void add(int position) {
		match[position] = '1';
		matchCounter++;
	}
	
	
	
	
}
