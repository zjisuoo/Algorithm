//final 에 메소드를 붙임
//final 을 메소드에 붙이면 메소드 오버라이딩 허락 안함
class FinalMethod{
	String str = "JAVA";
	public final void setStr(String s){
		str = s;
		System.out.println(str);
	}
}
class FinalEx extends FinalMethod{
	int a = 10;
	public void setStr(String s){
		//메소드 오버라이딩 금지 부모클래스의 해당메소드에 final붙임
		str+=s;
		System.out.println(str);
	}
}
public class final_2{
	public static void main(String[] args){
		FinalEx ft = new FinalEx();
	}
}