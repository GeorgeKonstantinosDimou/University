/*
 * For this program to work you need to set the Memory Allocation a little bigger
 * java -Xmx2048m BufferSizeMax.java  (in terminal)
 */


public class BufferSizeMax {

	private int[] contents;
	private int size = Integer.MAX_VALUE - 2;
	private int front, back;
	private int counter = 0;
	private boolean bufferFull = false;
	private boolean bufferEmpty = true;
	
	
	public BufferSizeMax() {
		contents = new int[size];
		this.front = 0;
		this.back = (size - 1);
		for(int i=0;i<size;i++) 
			contents[i] = 0;	
	}
	
	public synchronized void put(int data) {
	
		while (bufferFull) {
			try {
				wait();
			} catch (InterruptedException e) {}
		}
			contents[back] = data;	
			System.out.println("Item " + data + " added in loc " + back + ". Count = " + counter);
			counter++;
			back = (back + 1);
			bufferEmpty = false;
			//buffer was empty
			if (counter == 1) notifyAll();
	}
	
	public synchronized int get() {
		
		while (bufferEmpty) {
			try {
				wait();
			} catch (InterruptedException e) {}
		}
			int data = contents[front];
			System.out.println("Item " + data + " removed from loc " + front + ". Count = " + counter);
			front = (front + 1);
			counter--;
			bufferFull = false;
			if (counter==0) 
			{
				bufferEmpty = true;
				System.out.println("The buffer is empty");
			}
			//buffer was full
			if (counter == size - 1) notifyAll();
			return data;
		}		
}
