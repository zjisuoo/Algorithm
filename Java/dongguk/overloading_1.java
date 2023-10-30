//Method overloading
//동일한 이름으로 메소드를 여러번 재정의 하는것(다형성.Polymorphism)
//메소드 이름, 매개변수의 자료형, 매개 변수의 개수
//메소드 이름은 같고, 매개변수의 자료형과 매개변수의 개수는 달라야함
public class overloading_1{
	static void printstr(String the_string){
		System.out.println(the_string);
	}
	static void printstr(char the_char, int repeat_cnt){
		for(int i = 0 ; i<repeat_cnt ; i++)
			System.out.println(the_char);
	}
	public static void main(String[] args){
		printstr("APPLE"); //메소드 호출
		printstr('A',3);
	}
}