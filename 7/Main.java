import java.lang.System;
import java.util.Scanner;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		AbstractBoard [] a = new AbstractBoard[2];
		a[0] = new BoardArray1D();
		a[1] = new BoardArray2D();
		Scanner scan = new Scanner(System.in);
		int c = 0 ;
		if (args.length == 1) {
			for(int i = 0;i<2;i++){
				a[i].readFromFile(args[0]);
			}
			
		} else if(args.length == 0){
			int x = scan.nextInt();
			int y = scan.nextInt();
			for(int i = 0;i<2;i++){
				a[i].setSize(x,y);
			}
			
		}
		String input = new String();
		for(int x = 0;x<2;x++){
			System.out.println(a[x]);
		}
		while (!a[0].isSolved()) {
			input = scan.next();
			
			for(int x = 0;x<2;x++){
				a[x].move(input.charAt(0));
			}
			for(int x = 0;x<2;x++){
				System.out.println(a[x]);
			}
			System.out.println(a[0].equals(a[1]));
			if(c == 1)a[1].move('l');
			
			c++;
		}
		try {
			if(args.length == 1){
				for(int x = 0;x<2;x++){
					a[x].writeToFile(args[0]);
				}
			}else if(args.length == 0){
				for(int x = 0;x<2;x++){
					System.out.printf("Filename that will be created:");
					a[x].writeToFile(scan.next());
				}
			}
			
		} catch (IOException e) {
			//TODO: handle exception
		}
		scan.close();
	}

	static boolean isValidSequence(AbstractBoard [] arrayOfAbsBoard){
        for (int i = 0; i < AbstractBoard._numberOfBoards -1 ; i++) {
			if(!arrayOfAbsBoard[i].isDiffTwo(arrayOfAbsBoard[i+1])){
				return false;
			}
		}
		return true;
    }
}
