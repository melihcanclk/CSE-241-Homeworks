import java.lang.System;
import java.util.Scanner;

public class FirstProject {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int last = 10;
		int i = 0;
		int x = scan.nextInt();
		int y = scan.nextInt();
		NPuzzle puzzle = new NPuzzle(y,x);
		String input = new String();
		puzzle.print();
		while(i<last) {	
			input = scan.next();
			puzzle.move(input.charAt(0));
			puzzle.print();
			i++;
		}
		scan.close();
	}
}
