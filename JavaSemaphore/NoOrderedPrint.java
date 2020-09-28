class MyString {
	StringBuffer sb;
	int countCapLetters = 0;

	public MyString() {
		sb = new StringBuffer("");
	}

	public void  appendChar(Character s) {
		sb.append(s);
	}

	public String getString() {
		return sb.toString();
	}
}

class ThreadA implements Runnable {
	MyString myString;

	public ThreadA (MyString myString) {
		this.myString = myString;
	}

	public void run() {
		myString.appendChar('A');
		myString.appendChar('a');
	}
}

class ThreadB implements Runnable {
	MyString myString;

	public ThreadB (MyString myString) {
		this.myString = myString;
	}

	public void run() {
		myString.appendChar('B');
		myString.appendChar('b');
	}
}

	public class NoOrderedPrint {
		public static void main (String[] args) {
			MyString myString = new MyString();

			Thread thrd1 = new Thread(new ThreadA(myString));
			Thread thrd2 = new Thread(new ThreadB(myString));

			thrd1.start();
			thrd2.start();
			try{
				thrd1.join();
				thrd2.join();
			} catch (InterruptedException ie) {}

			System.out.println("String final: "+myString.getString());
			
		}
	}
