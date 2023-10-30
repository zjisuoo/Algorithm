interface IHello{
	public abstract void sayHello(String name);
	//추상메소드
}
interface IGoodBye{
	public abstract void sayGoodBye(String name);
	//추상메소드
}
class SubClass implements IHello, IGoodBye{
	public void sayHello(String name){
		//메소드오버라이딩
		System.out.println(name+"Hello");
	}
	public void sayGoodBye(String name){
		//메소드오버라이딩
		System.out.println(name+"Bye");
	}
}
class interface_3{
	public static void main(String[] args){
		SubClass test = new SubClass();
		//test객체생성
		String a1 = "kim";
		test.sayHello(a1);
		test.sayGoodBye(a1);
	}
}