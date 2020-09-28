public class MutableInteger {
	private int value = 0;
	private int temp;

	public int getValue() {
		return value;
	}

	public void incValue() {
		temp = value;
		temp = temp + 1;
		value = temp;
	}
}
