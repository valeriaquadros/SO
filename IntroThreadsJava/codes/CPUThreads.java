class CPUWork implements Runnable {
	public CPUWork() {
	}

	public void run() {
		int i = 1;
		
		while(true)
			i = i*1;
	}
}

public class CPUThreads {
	public static void main (String[] args) {
		int i;
		
		if (args.length < 1) {
			System.out.println("Usage: java CPUThreads <numThreads>");
			return;
		}
		
		int numThreads = new Integer(args[0]);
		
		Thread threads[] = new Thread[numThreads];

		for(i = 0; i < numThreads; i++) {
			threads[i] = new Thread(new CPUWork());
			threads[i].start();
		}
	}
}
