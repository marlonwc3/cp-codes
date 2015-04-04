import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	static BigInteger f(BigInteger b, int k){
		BigInteger r = new BigInteger("1");
		while( k > 0 ) {
			r = r.multiply(b);
			b = b.add(new BigInteger("-1") );
			//System.out.println("R: " + r);
			//System.out.println("B: " + b);
			k--;
		}
		
		
		return r;
		
	}
	
	
	public static void main(String[] args) {
		Scanner in =  new Scanner(System.in);
		String str = in.nextLine();
	//	System.out.println("Str: " + str);
		BigInteger mybig = new BigInteger(str);
		BigInteger r = new BigInteger("0");
	//	System.out.println(mybig);
		//System.out.println(r);
		int k = Integer.parseInt(str);
		for(int i = 2; i <= k; i++){
		//	System.out.println("rESULT: " + f(mybig, i) );
			r= r.add (f(mybig, i));
		}
		System.out.println(r);
		

	}

}
