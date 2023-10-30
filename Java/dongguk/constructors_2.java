class TV1{
	private int nSize = 0;
	public TV1(int nNewSize){
		nSize = nNewSize;
		System.out.println(nSize);
	}
	public TV1(){
		nSize = 20;
		System.out.println(nSize);
	}
}
public class constructors_2{
	public static void main(String[] args){
		TV1 tv1 = new TV1(10);
		TV1 tv2 = new TV1();
	}
}