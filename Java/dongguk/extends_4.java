class A1{
	int a = 10;
	int b = 20;
	void display(){
		System.out.println("A class"+a+","+b);
	}
}
class B1 extends A1{
	int a = 100;
	int b = 200;
	void display(){
		System.out.println("B class"+a+","+b);
	}
	void show(){
		super.display(); 
		//부모클래스의 display()메소드호출
		this.display();
		//자신의 클래스에 있는 display()메소드호출
		int total = this.a + this.b + super.a + super.b;
		System.out.println("total ="+total);
	}
}
public class extends_4{
	public static void main(String[] args){
		B1 obj = new B1();
		obj.show();
	}
}