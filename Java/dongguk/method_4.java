public class chap4_5{
	static void sum(int n){
		int i;
		int tot=0;

		for(i=1;i<=n;i++)
			tot=tot+i;

		System.out.println("1~"+n+"total"+tot);
	}
	public static void main(String[] args){
		sum(5);
		sum(10);
	}
}