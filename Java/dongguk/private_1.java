public class p1{
		private int x;
		private int y;
		public void setX(int a){
			x=a;
		}
		public int getX(){
			return this.x;
			}
		public void setY(int a){
			y=a;
		}
		public int getY(){
			return this.y;
		}	
	}
	public class private_1{
		public static void main(String[] args){
			p1 pp = new p1();
			pp.setX(10);
			pp.setX(20);
			System.out.println(pp.getX());
			System.out.println(pp.getY());
		}
	}
