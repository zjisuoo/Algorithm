public class string_1{
	public static void main(String[] args){
		int a =10, b = 10;
		if(a==b)
			System.out.println("SAME");
		else
			System.out.println("NOT SAME");

		String str01 = new String("HAPPY VIRUS");
		String str02 = new String("HAPPY VIRUS");

		if(str01==str02)
			//저장된 장소가 같을 때
			System.out.println("SAME");
		else
			System.out.pritnln("NOT SAME");

		if(str01.equals(str02))
			//값이 같을 때
			System.out.println("SAME");
		else
			System.out.pritnln("NOT SAME");
	}
}