interface Drawable{
	public abstract void draw();
}
abstract class Shape{
	public double res = 0;
	public abstract double area();
	public void printArea(){
		System.out.println("면적"+res);
	}
}
class Rectangle extends Shape implements Drawable{
	public int w = 10;
	public int h = 10;
	public double araa(){
		res = w*h;
		return res;
	}
	public void draw(){
		System.out.println("DRAW RECTANGLE");
	}
}
public class interface_4{
	public static void main(String[] args){
		Rectangle ref = new Rectangle();
		ref.area();
		ref.printArea();
		ref.draw();
	}
}