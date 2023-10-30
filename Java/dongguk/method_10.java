public class method_9{
	static void sum_func(int a, int b, int c){
		System.out.print("SUM IS"+(a+b+c));
	}
	static void avg_func(int a, int b, int c){
		System.out.print("AVG IS"+(a+b+c)/3);
	}
	public static void main(String[] args){
		int num0=Integer.parseInt(args[0]);
		int num1=Integer.parseInt(args[1]);
		int num2=Integer.parseInt(args[2]);
		sum_func(num0,num1,num2);
		avg_func(num0,num1,num2);
	}
}