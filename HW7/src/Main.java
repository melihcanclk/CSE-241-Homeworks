import java.lang.System;
import java.util.Scanner;
import java.io.*;

/** 
* 
* @author Melihcan Çilek 
*/

public class Main {

	public static void main(String[] args) throws IOException {
		AbstractBoard[] a = new AbstractBoard[2];
		a[0] = new BoardArray1D();
		a[1] = new BoardArray2D();

		Scanner scan = new Scanner(System.in);
		System.out.print("1-> scan Files \n2-> create board\n");
		String decision = scan.next();
		while (!decision.equals("2") && !decision.equals("1")) {
			System.out.print("Invalid input. Please try again\n");
			System.out.print("1-> scan Files \n2-> create board\n");
			decision = scan.next();
		}
		if (decision.equals("1")) {
			System.out.print("Enter first file name without .txt extension:");
			decision = scan.next();
			a[0].readFromFile(decision + ".txt");
			System.out.print("Enter second file name without .txt extension:");
			decision = scan.next();
			a[1].readFromFile(decision + ".txt");

		} else if (decision.equals("2")) {
			System.out.print("Enter X length of board:");
			int x = scan.nextInt();
			System.out.print("Enter Y length of board:");
			int y = scan.nextInt();
			for (int i = 0; i < 2; i++) {
				a[i].setSize(x, y);
			}

		}

		for (int i = 0; i < 2; i++) {
			printControlStatement(a);
			a[0].move('l');

		}
		for (int i = 0; i < 2; i++) {
			printControlStatement(a);
			a[1].move('l');
		}
		a[0].writeToFile("test1.txt");
		a[1].writeToFile("test2.txt");

		for (int i = 0; i < 2; i++) {
			printControlStatement(a);
			a[0].move('r');

		}
		for (int i = 0; i < 2; i++) {
			printControlStatement(a);
			a[1].move('r');

		}

		for (int i = 0; i < 2; i++) {
			printControlStatement(a);
			a[0].move('u');

		}
		for (int i = 0; i < 2; i++) {
			printControlStatement(a);
			a[1].move('u');

		}
		for (int i = 0; i < 2; i++) {
			printControlStatement(a);
			a[0].move('d');

		}
		for (int i = 0; i < 2; i++) {
			printControlStatement(a);
			a[1].move('d');

		}
		printControlStatement(a);
		try {

			for (int x = 0; x < 2; x++) {
				System.out.printf("Filename that will be created for %d . board without .txt extension:", x + 1);
				a[x].writeToFile(scan.next() + ".txt");
			}

		} catch (IOException e) {
			System.out.printf("IOException\n");
		}
		scan.close();
	}

	static void printControlStatement(AbstractBoard[] a) {
		for (int x = 0; x < 2; x++) {
			System.out.println(a[x]);
		}
		System.out.printf("Is sequence valid?: %s\n", isValidSequence(a));
		System.out.printf("Is two board equal?: %s\n", a[0].equals(a[1]));
		System.out.printf("Is 1st board solved?: %s\n", a[0].isSolved());
		System.out.printf("Is 2nd board solved?: %s\n", a[1].isSolved());
	}

	static boolean isValidSequence(AbstractBoard[] arrayOfAbsBoard) {
		for (int i = 0; i < AbstractBoard._numberOfBoards - 1; i++) {
			if (!arrayOfAbsBoard[i].isDiffTwo(arrayOfAbsBoard[i + 1])) {
				return false;
			}
		}
		return true;
	}
}
