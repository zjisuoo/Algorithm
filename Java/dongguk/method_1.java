class Grade{
	int kor = 60;
	int eng = 60;
	int mat = 60;
}
public class method_11{
	public static void main(String[] args){
		int total;
		double avg;
		Grade stu1 = new Grade();
		total = stu1.kor+stu1.eng+stu1.mat;
		avg = total/3.0;
		System.out.println("KOREA ="+stu1.kor);
		System.out.println("ENGLISH ="+stu1.eng);
		System.out.println("MATH ="+stu1.mat);
		System.out.println("SUM ="+total);
		System.out.println("AVERAGE ="+avg);


	}
}