public class chap3_11{
	public static void main(String[] args){
		try{
			String c=null;
			System.out.println("String value is"+c.toString());
		}
		catch(Exception e){
			System.out.println(e);
		}
		finally{
			System.out.println(">>finally sentence is");
		}
	}
}