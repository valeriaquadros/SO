import java.util.concurrent.Semaphore;

class SyncAccumulator implements Runnable {
	private MutableInteger sharedValue;
	private Semaphore semaphore;

	public SyncAccumulator (MutableInteger acc, Semaphore semaphore) {
		this.sharedValue = acc;
		this.semaphore = semaphore;
	}

	public void run() {
		for (int i = 0; i < 1000; i++) {
			try{
				semaphore.acquire();
				sharedValue.incValue();
			}
			catch (InterruptedException e) {
        			e.printStackTrace();
    			} finally {
        			semaphore.release();
    			}
		}
	}
}

	public class SharedDataWSem {
		public static void main (String[] args) {
			Semaphore semaphore = new Semaphore(1);
			
			// cria o objeto a ser compartilhado
			MutableInteger acc = new MutableInteger();

			Thread thrd1 = new Thread(new SyncAccumulator(acc, semaphore));
			Thread thrd2 = new Thread(new SyncAccumulator(acc, semaphore));

			thrd1.start();
			thrd2.start();
			try{
				thrd1.join();
				thrd2.join();
			} catch (InterruptedException ie) {}

			System.out.println("O contador é de "+	acc.getValue());
			
		}
	}
