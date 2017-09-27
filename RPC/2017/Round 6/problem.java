import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class problem {
	public static void main(String[] args) {
		MyScanner s = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out), true);
		
		int t = s.nextInt();
		String n ;
		BigInteger bn;
		
		while(t>0){
			
			n = s.nextLine();
			
			if(n.equals("0")){ System.out.println(1); }
			else if(n.equals("1") ){ System.out.println(66);
			}else{
				
				bn = new BigInteger(n);
				bn = bn.add(new BigInteger("3"));	
				String res = bn.mod(new BigInteger("5")).toString();
				if(res.equals("0")){
					out.println(56);
				}else if(res.equals("1")){
					out.println(96);
				}else if(res.equals("2")){
					out.println(36);
				}if(res.equals("3")){
					out.println(76);
				}else if(res.equals("4")){
					out.println(16);
				}
			}
			t--;
		}
		
		out.close();
	}
	
	//-----------PrintWriter for faster output---------------------------------
    public static PrintWriter out;
 
    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;
 
        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
        double nextDouble() { return Double.parseDouble(next()); }
         
        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
