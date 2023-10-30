class Circle1{
	int r;
	public Circle1(int a){  //생성자 통해 반지름 지정
		r =a;
	}
	public double getArea(){
		return r*r*3.14;
	}
}
public class circle_2{
	public static void main(String[] args){
		Circle1 c = new Circle1(5);
		System.out.println(c.getArea());
	}
}