class PrintHello implements Runnable {
	private int id;

	public PrintHello(int id) {
		this.id = id;
	}

	public void run() {
		System.out.println("Olá Mundo! Saudações da thread "+id);
	}
}

public class HelloWorld {
	public static void main (String[] args) {
		int i;
		Thread threads[] = new Thread[10];

		for(i = 0; i < 10; i++) {
			threads[i] = new Thread(new PrintHello(i));
			threads[i].start();
		}
	}
}
