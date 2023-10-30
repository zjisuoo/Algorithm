public class chap3_9{
	public static void main(String[] args){
		String [] name={"kim","lee","hong","song","park"};
		int [][]score={{85,60,70,0,0},{90,95,80,0,0},{75,80,60,0,0},{80,70,95,0,0},{100,65,80,0,0}};
		int r,c;
		for(r=0;r<5;r++){
			for(c=0;c<3;c++){
				score[r][3]=score[r][3]+score[r][c];
			}
			score[r][4]=score[r][3]/3;
		}
		System.out.println("print result");
		System.out.println("name\tkorean\tenglish\tmath\tsum\taverage");
		for(r=0;r<5;r++){
			System.out.print(name[r]+":\t");
			for(c=0;c<5;c++){
				System.out.print(score[r][c]+"\t");
			}
			System.out.println();
		}
	}
}