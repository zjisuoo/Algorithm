class Point2D{
	int x = 10;
	int y = 20;
	public void showpoint(){
		System.out.println(x+","+y);
	}
}
class Point3D extends Point2D{
	//Point2D클래스(부모클래스) 상속을 받아 Point3D클래스(자식클래스) 생성
	int z = 30;
	public void showpoint(){ 
		//메소드오버라이딩=자식클래스에서 메소드 재정의
		System.out.println(x+","+y+","+z);
	}
}
public class extends_3{
	public static void main(String[] args){
		Point3D pt = new Point3D();
		pt.showpoint();
	}
}