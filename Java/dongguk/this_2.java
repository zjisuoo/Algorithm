public Point03({
	public Point03(int x, int y){
		this.x=x;
		this.y=y;
	}
	public void setX(int x){
		this.x=x;
	}
	public void showPoint(){
		System.out.println(x+","+y);
	}
	public class this_2{
		Point03 pt01 = new Point03(10,20);

		pt01.showPoint();
		pt01.setX(30);
		pt01.showPoint();
	}
}