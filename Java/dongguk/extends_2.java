class A{
	int a = 1;
}
class B extends A{ 
	//자식클래스(=서브클래스) extends 부모클래스(=슈퍼클래스)
	int b = 2;
}
class C extends B{
	int c = 3;
}
public class extends_2{
	public static void main(String[] args){
		C ins = new C();
		//C클래스의 객체 ins
		System.out.println(ins.a);
		System.out.println(ins.b);
		System.out.println(ins.c);
	}
}