//final 
//자료형으로 선언된 변수 앞에 final 붙이면 변수느 상수가 됨
//저장된 값 변경 할수 없음
class FinalMember{
	final int a = 10;
	//a변수 선언(final - 상수가 되서 변경안됨)
	public void setA(int a){
	//this.a = a;
	//위에서 a변수를 final을 붙여 상수가 되었기 때문에 값을 변경 할 수 없음
	}
}
public class final_1{
	public static void main(String[] args){
		FinalMember ft = new FinalMember();
		final int a = 1000;
		ft.setA(100);
		System.out.println(a);
	}
}