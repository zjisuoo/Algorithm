//static으로 선언된 멤버들은 해당 클래스당 오직 1개만 생성 
//여러 객체들에 의해 공유하고자 할 때 사용
class Account{
	int count;
	static int total;
	Account(int amount){
		count = count+amount;
		count = totla+amount;
	}
}
public class account_1{
	public static void main(String[] args){
		Account acc01 = new Account(10);
		//Acount 클래스 접근하기 위해 acc01객체 생성
		//자동으로 Account(int amount)생성자 호출
		System.out.println(acc01.total+","+acc01.count);

		Account acc02 = new Account(10);
		System.out.println(acc02.total+","+acc02.count);

		Account acc03 = new Account(10);
		System.out.println(acc03.total+","+acc03.count);
	}
}