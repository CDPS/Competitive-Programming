import java.math.BigInteger;
import java.util.Scanner;

class Main {

	static BigInteger a [] = new BigInteger[10001];

	public static void main(String[] args) {

		precalc();
		Scanner s = new Scanner(System.in);

		int n;
		while(s.hasNext()) {
			try {
				n = s.nextInt();
				System.out.println(n+"!");
				System.out.println(a[n].toString());
			}catch(NumberFormatException ex) {
				break;
			}
		}
	}

	public static void precalc() {

		a[0]= new BigInteger("1");

		BigInteger ai ;
		for(int i=1;i<=1000;i++) {
		   ai= new BigInteger(""+i);
		   a[i] = ai.multiply(a[i-1]);
		}
	}
}
