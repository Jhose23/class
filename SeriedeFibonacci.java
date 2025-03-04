
public class SeriedeFibonacci {

	public static void main(String[] args) {
		int n = 4;
		int a = 1 , b = 1;
		System.out.print(a + "," + b + ",");
		for (int i = 2; i < n; i++) {
			System.out.print(a  + b  +  "," );
			b = a + b;
			a = b - a;
		}

	}

}
