public class overloading_3{
	static void prn(int ...num){  
		for(int i=0 ; i<num.length ; i++)
			System.out.print(num[i]+"\t");
		System.out.println();
	}
	public static void main(String[] args){
		prn(10,20,30,40);
		prn(10,20,30);
		prn(40,50);
		prn(60);
	}
}