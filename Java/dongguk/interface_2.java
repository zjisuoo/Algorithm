interface Drawable1{
	//Drawable 인터페이스
	public abstract void draw();
	//추상메소드
}
class Circle1 implements Drawable1{
	public void draw(){
		//메소드오버라이딩
		System.out.println("DRAW CIRCLE.");
	}
}
public class interface_2{
	public static void main(String[] args){
		Circle1 ref = new Circle1();
		//객체생성
		ref.draw();
	}
}