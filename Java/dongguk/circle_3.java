class Circle{
	int r;
	public Circle(int a){
		r=a;
	}
	public double getArea(){
		return r*r*3.14;
	}
}
class Cylinder{
	Circle c;
	int h;
	public Cylinder(Circle a, int b){
		c=a;
		h=b;
	}
	public double getVolume(){
		return c.getArea()*h;
	}
}
public class circle_3{
	public static void main(String[] args){
		Circle c = new Circle(7);
		int h=8;
		Cylinder cy = new Cylinder(c,h);
		System.out.println(cy.getVolume());
	}
}