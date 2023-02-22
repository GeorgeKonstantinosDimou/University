
public class BufferSize1 {

	private int[] contents;
	private final int size = 1;
	private int front, back;
	private int counter = 0;
	private boolean bufferFull = false;
	private boolean bufferEmpty = true;
	
	
	public BufferSize1() {
		contents = new int[size];
		this.front = 0;
		this.back = size - 1;
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
			back = (back + 1) % size;
			counter++;
			bufferEmpty = false;
			if (counter==size)
			{
				System.out.println("The buffer is full");
				bufferFull = true;
			}
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
			front = (front + 1) % size;
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
