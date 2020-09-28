class Accumulator implements Runnable {
	private MutableInteger sharedValue;

	public Accumulator (MutableInteger acc) {
		this.sharedValue = acc;
	}

	public void run() {
		for (int i = 0; i < 1000; i++)
			sharedValue.incValue();
	}
}

	public class SharedData {
		public static void main (String[] args) {
			
			// cria o objeto a ser compartilhado
			MutableInteger acc = new MutableInteger();

			Thread thrd1 = new Thread(new Accumulator(acc));
			Thread thrd2 = new Thread(new Accumulator(acc));

			thrd1.start();
			thrd2.start();
			try{
				thrd1.join();
				thrd2.join();
			} catch (InterruptedException ie) {}

			System.out.println("O contador é de "+	acc.getValue());
			
		}
	}
