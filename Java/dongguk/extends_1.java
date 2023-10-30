//상속
//이미 정의된 훌륭한 클래스를 상속받아 새로운 클래스를 만드는 것
//기존 클래스의 상속을 받기 위해 extends 키워드 사용
//프로그램을 손쉽게 재사용하여 새로운 기능을 추가하고자 할 경우 사용
class A{
	int a = 1;
}
public class extends_1{
	public static void main(String[] args){
		A ins = new A();
		System.out.println(ins.a);
	}
}