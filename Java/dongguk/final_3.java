//class에 final을 붙이면 상속못함
final class FindClass{
	String str = "JAVA";
}
class FinalEx{ //extends FinalClass - error 발생
	int a = 10;
	public voic setA(int a){
		this.a = a;
	}
}
public class final_3{
	public static void main(String[] args){
		FinalEx1 fe = new FinalEx1();
	}
}