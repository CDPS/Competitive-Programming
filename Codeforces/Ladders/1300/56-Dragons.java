import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

	 public static void main(String[] args) {
	        // TODO Auto-generated method stub
	        Scanner s = new Scanner(System.in);

	        int st = s.nextInt();
	        int n = s.nextInt();
	        PriorityQueue<int[]> p=new PriorityQueue<>(new Compar());

	        int x;
	        int y;
	        for(int i=0;i<n;i++){
	            x=s.nextInt();
	            y=s.nextInt();
	            int []b= {x,y};
	            p.add(b);
	        }

	        boolean res=true;
	        while(!p.isEmpty()){
	            int[] aux = p.poll();
	            if(st>aux[0]){
	               st+=aux[1];
	             }
	            else{
	            	res =false;
	            	break;
	            }

	        }

	        if(res)
	        	System.out.println("YES");
	        else
	        	System.out.println("NO");

	        s.close();
	    }

}

class Compar implements Comparator<int []>{

    @Override
    public int compare(int[] a, int[] b) {
        // TODO Auto-generated meth

        if(a[0]<b[0]){
            return -1;
        }else if(a[0]==b[0] && a[1]>b[1]){
            return -1;
        }
        else{
            return 1;
        }
    }

}
