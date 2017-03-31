
import java.util.Scanner;

public class A1005 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner in = new Scanner(System.in);
		
		String num = in.nextLine();
		
		int sum = 0;
		
		for (int i = 0; i < num.length(); i++){
			char ch = num.charAt(i);
			int n = ch - '0';
			sum += n;
		}
		
		String[] english = {"zero", "one", "two", "three", "four", "five", "six",
				"seven", "eight", "nine"};
		
		String str = String.valueOf(sum);

		for (int i = 0; i < str.length(); i++){
			if (i == 0)
				System.out.print(english[str.charAt(i) - '0']);
			else
				System.out.format(" %s", english[str.charAt(i) - '0']);
		}

	}

}
