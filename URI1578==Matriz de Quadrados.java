import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] l = new int[105];
		BigInteger[][] m = new  BigInteger[105][105];		
		int caso = Integer.parseInt(in.nextLine()), n, len;
		BigInteger b;
		String s;
		long k;
		boolean first = true;
		for (int t = 0; t <caso; t++) {
			if(!first) System.out.println("");
			n = Integer.parseInt(in.nextLine());
			for(int i =0; i < n; i++)l[i]=0;
			for(int i= 0; i < n; i++){
				s = in.nextLine();
				String bi = "";
				ArrayList<String> vs = new ArrayList<String>();
				for(int x = 0; x < s.length(); x++){
					if(s.charAt(x) == ' ' ){
						vs.add(bi);
						bi = "";
					}
					else bi += s.charAt(x);
				}
				vs.add(bi);
				int j = 0;
				for(int x = 0; x < vs.size(); x++){
					s = vs.get(x);
					b = new BigInteger(s);
					b = b.pow(2);
					m[i][j] = b;
					s = b.toString();
					len = s.length();
					l[j] = Math.max(l[j], len); 
					j++;
				}
			}
			System.out.println("Quadrado da matriz #" + (t+4)+ ":");	
			for(int i =0 ; i < n; i++){
				for(int j = 0; j < n; j++){
					s = m[i][j].toString();
					len = l[j] - s.length();
					while(( len--) > 0  ){ System.out.print(" "); }
					System.out.print(m[i][j].toString());
					if(j!=n-1) System.out.print(" ");
				}
				System.out.println(""); 
			}
			first = false;
		}
	}
}
