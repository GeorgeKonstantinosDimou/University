/*
 * Locking the whole buffer using semaphores. Pay close attention to what
 * each semaphore is acquiring and releasing. Semaphore(0) will wait for 
 * a release first before being able to acquire, while semaphore(1) 
 * will start on the first acquire
 */

import java.util.concurrent.Semaphore;

public class BufferFor1 {

	private int[] contents;
	private int size;
	private int front, back;
	private int counter = 0;
	private Semaphore bufferMutex = new Semaphore(1);
	private Semaphore bufferFull = new Semaphore(0);
	private Semaphore bufferEmpty;
	
	
	
	public BufferFor1(int aSize) {
		this.size = aSize;
		contents = new int[size];
		this.front = 0;
		this.back = size - 1;
		for(int i=0;i<size;i++) 
			contents[i] = 0;
		this.bufferEmpty = new Semaphore(size);
		
	}
	
	public void put(int data) {
	
			try {
				bufferEmpty.acquire();
			} catch (InterruptedException e) {}
			try {
				bufferMutex.acquire();
			}catch (InterruptedException e) {}
			back = (back + 1) % size;
			contents[back] = data;
			counter++;
			System.out.println("Item " + data + " added in loc " + back + ". Count = " + counter);
			if (counter==size) System.out.println("The buffer is full");
			bufferMutex.release();
			bufferFull.release();
	}
	
	public int get() {
			int data = 0;
			try {
				bufferFull.acquire();
			} catch (InterruptedException e) {}
			try {
				bufferMutex.acquire();
			} catch (InterruptedException e) {}
			data = contents[front]; 
			System.out.println("Item " + data + " removed from loc " + front + ". Count = " + counter);
			front = (front + 1) % size;
			counter--;
			if (counter==0)System.out.println("The buffer is empty");
			bufferMutex.release();
			bufferEmpty.release();
			return data;
		}		
}
