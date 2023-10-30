import java.util.Scanner;
class Grade1{
	private int sum;
	private double avg;
	String point;
	public int getSum(){
		return sum;
	}
	public void setSum(int x, int y, int z){
		sum = x+y+z;
	}
	public double getAvg(){
		return sum/3.0;
	}
	public void setGrade(){
		String grade = "";
		avg = sum/3.0;
		if(avg<=90.0) 
			grade = "A";
		else if(avg>=80.0)
			grade = "B";
		else if(avg>=70.0)
			grade = "C";
		else if(avg>=60.0)
			grade = "D";
		else
			grade = "F";
		return grade;
	}
}
public class private_2{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		System.out.println("KOREAAN, ENGLISH, MATH SCORE = ");
		int kor = scanner.nextInt();
		int eng = scanner.nextInt();
		int mat = scanner.nextInt();

		System.out.println("KOREAN= "+kor);
		System.out.println("ENGLISH= "+eng);
		System.out.println("MATH= "+mat);

		Grade1 stu1 = new Grade1();
		stu1.setSum(kor,eng,mat);
        System.out.println("SUM= "+stu1.getSum());
		System.out.println("AVERAGE= "+stu1.getAvg());
		System.out.println("SCORE= "+stu1.getGrade());

	}
}