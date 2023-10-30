public class chap3_7{
	public static void main(String[] args){
		int[] num={1,2,3,4,5};
		String names[]={"apple","pear","banana","starawberry","grape"};
		int sum=0;

		for(int i=0;i<num.length;i++){
			sum=sum+num[i];
		}
		System.out.println("use for sum"+sum);
		sum=0;
		for(int k:num)
			sum=sum+k;
		System.out.println("for...each sentence"+sum);
		for(int i=0;i<names.length;i++){
			System.out.print(names[i]+" ");
		}
		System.out.println();

		for(String s:names)
			System.out.print(s+" ");
		System.out.println();
	}
}