public class Consumer extends Thread {
	private BufferFor1 buff;
	private int scale;

	// Constructor
	public Consumer(BufferFor1 b, int s) {
		this.buff = b;
		this.scale = s;
	}

	// Producer runs for reps times with random(scale) intervals
	public void run() {
		int value;
		while (true) {
			try {
				sleep((int)(Math.random()*scale));
			} catch (InterruptedException e) { }
			value = buff.get();
		}
	}
}
