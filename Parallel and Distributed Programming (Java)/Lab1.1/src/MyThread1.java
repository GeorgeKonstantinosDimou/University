
public class MyThread1 extends Thread{

	private int myID;
    private int totalThreads;

    /* constructor */
    public MyThread1(int myID, int totalThreads) {
        this.myID = myID;
        this.totalThreads = totalThreads;
    }

    /* thread code */
    public void run() {
        System.out.println("hello from thread " + myID + " out of " + totalThreads);
        System.out.println("thread " + myID + " exits");
    	} 
}
