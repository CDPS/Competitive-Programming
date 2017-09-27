import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int t,caseno=1;

        t = s.nextInt();
        s.nextLine();
        while(t>0) {

            String st = s.nextLine();
            String ar[]= st.split(" ");

            BigInteger a = new BigInteger(ar[0]);
            BigInteger b = new BigInteger(ar[1]);
            b= b.abs();

            BigInteger res = a.mod(b);

            if(res.equals(new BigInteger("0") ) )
                System.out.printf("Case %d: divisible\n", caseno++);
            else
                System.out.printf("Case %d: not divisible\n", caseno++);

            t--;
        }
        s.close();
    }
}
