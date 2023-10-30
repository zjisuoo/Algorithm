//import 
//import 구문을 기술하면 패키지를 일일이 클래스 이름앞에 붙이지 않아도 됨
//외부의 클래스를 사용해야 하는 경우 필요한 클래스를 불러들이는 역할을 함
//ex - import.java.lang.
import java.util.ArrayList;
public class import_1{
	public static void main(String[] args){
		ArrayList list = new ArrayList();
		//Ctrl+Shift+O 누르면 import java.util.ArrayList 생성됨
		//java.util.ArrayList list = new java.util.ArrayList(); - 오류 안남

		list.add("First");
		list.add("Second");

		for(int i = 0 ; i<list.size() ; i++)
			System.out.println(i+""+list.get(i));
	}
}