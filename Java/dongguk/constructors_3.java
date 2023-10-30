class Point02{
	int x;
	int y;
	public Point02(){
		System.out.println("constructors");
	}
	public Point02(int new_x, int new_y){
		x=new_x;
		y=new_y;
	}
	public void showPoint(){
		System.out.println(x+","+y);
	}
}
public class overloading_3{
	public static void main(String[] args){
		Point02 pt01 = new Point02();
		pt01.showPoint();

		Point02 pt02 = new Point02(100,200);
		pt02.showPoint();
	}
}