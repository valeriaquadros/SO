class MutableInteger{
	private int value = 0;
	public int getValue() {
		return value;
	}

	// Whats is wrong here?
	public void incValue() {
		int tmp = this.value;
		tmp = tmp + 1;
		this.value = tmp;
	}
}

class Summation implements Runnable {
	private int upper;
	private MutableInteger ValorSoma;

	public Summation (int upper, MutableInteger ValorSoma) {
		this.upper = upper;
		this.ValorSoma = ValorSoma;
	}

	public void run() {
		for (int i = 0; i < upper; i++)
			ValorSoma.incValue();
	}
}

public class Driver {
	public static void main (String[] args) {
		if (args.length > 0) {
			if (Integer.parseInt(args[0]) < 0)
				System.out.println(args[0] + "precisa ser >= 0.");
			else {
				// cria o objeto a ser compartilhado
				MutableInteger soma = new MutableInteger();
				int upper = Integer.parseInt(args[0]);
				Thread thrd1 = new Thread(new Summation(upper, soma));
				Thread thrd2 = new Thread(new Summation(upper, soma));
				thrd1.start();
				thrd2.start();
				try{
					thrd1.join();
					thrd2.join();
					System.out.println("A soma de "+upper+" é "+soma.getValue());
				} catch (InterruptedException ie) {}
			}
		}
		else
			System.out.println("Uso: Soma <Valor inteiro>");
	}
}