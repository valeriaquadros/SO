import java.io.IOException;

class NoWork implements Runnable {
	public NoWork() {
	}

	public void run() {
	}
}

public class CreationTime {
	public static void main(String[] args) {
		long startTime;
		long elapsedTime;
		int numCreations = 10000;
		
		// Measure the time to create threads
		startTime = System.nanoTime();	
        for(int i=0; i< numCreations; i++){
        	new Thread(new NoWork()).start();
        }
        elapsedTime = System.nanoTime() - startTime;
     
        System.out.println("Total execution time to create threads in millis: "
                + elapsedTime/1000000);

		// Measure the time to create processes
		startTime = System.nanoTime();	
        for(int i=0; i< numCreations; i++){
        	try {
                // Adjust the path for the process file
        		new ProcessBuilder("/home/valeria/lixo/nada").start();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
        }
        elapsedTime = System.nanoTime() - startTime;
     
        System.out.println("Total execution time to create processes in millis: "
                + elapsedTime/1000000);
	}
}