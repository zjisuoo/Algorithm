public class chap4_7{
	static void func(char ch, int n){
		int i;
		for(i=1;i<=n;i++)
			System.out.println(ch+" ");
	}
	public static void main(String[] args){
		func('@',2);
		func('A',7);
	}
}