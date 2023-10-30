public class return_4{
	static int pow(int a, int b){
		int sum=1;
		for(int i=1 ; i<=b ; i++)
			sum=sum*a;
		return sum;
	}
	public static void main(String[] args){
		int num0=Integer.parseInt(args[0]);
		int num1=Integer.parseInt(args[1]);
		System.out.println("RESULT IS"+pow(num0,num1));
	}
}