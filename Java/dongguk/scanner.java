import java.util.Scanner;
public class chap1_7{
	public static void main(String[] args){
		System.out.println("put on name,city,age,weight,married");

		Scanner scanner=new Scanner(System.in);
		String name=scanner.next();
		System.out.println("your name is"+name);
		String city=scanner.next();
		System.out.println("you live in"+city);
		int age=scanner.nextInt();
		System.out.println("you are"+age);
		double weight=scanner.nextDouble();cd
		System.out.println("you weight is"+weight);
		boolean single=scanner.nextBoolean();
		System.out.println("you are"+single);

		scanner.close();

	}
}