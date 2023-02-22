
public class MyThread2 extends Thread{
	
	private int myID;
    private int totalThreads;

    /* constructor */
    public MyThread2(int myID, int totalThreads) {
        this.myID = myID;
        this.totalThreads = totalThreads;
    }

    /* thread code */
    public void run() {
        System.out.println("hello from a DIFFERENT thread " + myID + " out of " + totalThreads);
        System.out.println("thread " + myID + " exits");
    } 
}
	
