public class method_10{
	static void pow(int a, int b){
		int sum=1;
		for(int i=1 ; i<=b ; i++)
			sum=sum*a;
		System.out.println("RESULT IS"+sum);
	}
	public static void main(String[] args){
		int num0=Integer.parseInt(args[0]);
		int num1=Integer.parseInt(args[1]);
		pow(num0,num1);
	}
}