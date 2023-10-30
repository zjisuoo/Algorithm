//abstract 추상클래스
//객체 생성 불가능
//abstract 예약어를 class 앞에
//추상클래스 내부에는 abstract()메소드가 하나 이상 존재
//추상메소드는 오버라이딩 되어야함
abstract class 도형{
	int it = 10;
	abstract void draw();
	//추상메소드, 내부작성 안하고 선언만함
}
public class abstract_1{
	public static void main(String[] args){
		도형 obj = new 도형();
	}
}