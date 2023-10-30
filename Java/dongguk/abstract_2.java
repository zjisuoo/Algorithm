abstract class 도형2{
	int i = 10;
	abstract void draw();
}
class 사각형 extends 도형2{
	void draw(){
		System.out.println("Draw square.");
	}
}
class abstract_2{
	public static void main(String[] args){
		사각형 obj = new 사각형();

		System.out.println(obj.j);
		obj.draw();
	}
}