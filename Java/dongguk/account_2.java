class Account{
	int count;
	static int total;
	Account(int amount){
		count = count+amount;
		count = totla+amount;
	}
	static void showTotal(){
		System.out.println("total :"+total);
	}
}
public class account_2{
	public static void main(String[] args){
		Account1.showTotal();
		//showTotal메소드가 static메소드이기 때문에
		//객체 생성 없이 클래스명만으로 호출가능


		Account1 pt1 = new Account1(10);
		//또는 객체 생성해서 호출해도 가능
		pt1.showTotal;
	}
}