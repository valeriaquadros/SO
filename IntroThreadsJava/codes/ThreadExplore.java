class PrintHello implements Runnable {
	private int id;

	public PrintHello(int id) {
		this.id = id;
	}

	public void run() {
		System.out.println("Hello World! Greetings from thread "+id);

		while(true) {
			if(Thread.currentThread().isInterrupted())
				break;
		}
	}
}

public class ThreadExplore {
	
	public static void main (String[] args) {
		int i;
		int numCores = Runtime.getRuntime().availableProcessors();

		System.out.println("Num cores: "+numCores);
		Thread threads[] = new Thread[2*numCores];

		for(i = 0; i < 2*numCores; i++) {
			threads[i] = new Thread(new PrintHello(i));
			threads[i].setPriority(Thread.MIN_PRIORITY);
			threads[i].start();
		}
		
		threads[i-1].setPriority(Thread.MAX_PRIORITY);

		threads[0].interrupt();

		while(true);
	}
	
}
