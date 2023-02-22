public class Producer extends Thread {
	private BufferFor1 buff;
	private int reps;
	private int scale;

	// Constructor
	public Producer(BufferFor1 b, int r, int s) {
		this.buff = b;
		this.reps = r;
		this.scale = s;
	}

	// Producer runs for reps times with random(scale) intervals
	public void run() {
		for(int i = 0; i < reps; i++) {
			buff.put(i);
			try {
				sleep((int)(Math.random()*scale));
			} catch (InterruptedException e) { }
		}
	}
}
