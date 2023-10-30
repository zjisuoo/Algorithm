//생성자의 이름은 클래스 이름과 동일
//생성자는 자료형을 지정하지 않음
//생성자는 선언 할때 컴파일러에 의해 자동 호출
class Point01{
	int x;
	int y;
	public Point01(){
		System.out.println(x+","+y);
	}
}
public class constructors_1{
	public static void main(String[] args){
		Point01 pt1 = new Point01();
		//Point01클래스 접근 위해 pt01 생성
		//객체 이용해 해당 클래스 접근하여 사용
		//객체 생성 시 자동으로 생성자 호출
		//객체 생성과 동시에 값을 초기화 하고자 할 경우 사용
	}
}