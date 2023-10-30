public class return_3{
	static int s_func(int a, int b, int c){
		return (a+b+c);
	}
	static double a_func(int a, int b, int c){
		return (a+b+c)/3;
	}
	public static void main(String[] args){
		int n0=Integer.pareseInt(args[0]);
		int n1=Integer.pareseInt(args[1]);
		int n2=Integer.pareseInt(args[2]);
		System.out.println("SUM IS"+s_func(n0,n1,n2));
		System.out.println("AVG IS"+a_func(n0,n1,n2));
	}
}