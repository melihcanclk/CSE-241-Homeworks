import java.lang.System;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		BoardArray2D puzzle = new BoardArray2D();
		Scanner scan = new Scanner(System.in);
		if (/*args.length == 1*/true) {
			puzzle.readFromFile("a.txt");
		}/* else if(args.length == 0){
			int x = scan.nextInt();
			int y = scan.nextInt();
			puzzle = new BoardArray2D(y,x);
		}*/
		int last = 10;
		int i = 0;
		String input = new String();
		System.out.println(puzzle);
		while (i < last) {
			input = scan.next();
			puzzle.move(input.charAt(0));
			System.out.println(puzzle);
			i++;
		}
		scan.close();
	}
}
