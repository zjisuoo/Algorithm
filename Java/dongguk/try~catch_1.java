public class chap3_10{
	public static void main(String[] args){
		//try...catch문은 프로그램 수행 중 예외가 발생하는 경우 처리해주는 문
		//예외는 프로그램 실행중의 외류가 발생하는 해우이로 예외처리 하지 않으면 강제종료
		//[예외발생 몇가지] 0으로 나눌경우, null값 처리 할 경우
		try{
			String c=null;
			System.out.println("String value:"+c.toString());
		}
		catch(NullPointerException e){
			System.out.println("exception");
			System.out.println(e);
		}
	}
}