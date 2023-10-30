abstract class 도형3{
	int i = 10;
	abstract void draw();
}
class 사각형3 extends 도형3{
	void draw(){
		System.out.println("Draw square.");
	}
}
class 원 extends 도형3{
	void draw(){
		System.out.println("Draw circle.");
	}
}
class 삼각형 extends 도형3{
	void draw(){
		System.out.println("Draw triangle.");
	}
}
class abstract_3{
	public static void main(String[] args){
		사각형3 obj1 = new 사각형3();
		원 obj2 = new 원();
		삼각형 obj3 = new 삼각형();

		obj1.draw();
		obj2.draw();
		obj3.draw();
	}
}