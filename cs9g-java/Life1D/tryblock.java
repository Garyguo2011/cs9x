import java.util.Scanner;

public class tryblock {
	public static void main (String[] args){
		Scanner sc = new Scanner(System.in);

		try{
			System.out.println("Please enter a number");
			int userInput = sc.nextInt();

			if(userInput<10 && userInput>1)
				System.out.println(userInput/10);
			else
				throw Exception;
			
		}catch(Exception e){
			System.out.println("Error");

		}
		
	}

}