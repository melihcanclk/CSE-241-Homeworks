import java.util.Scanner;
import java.io.*;

public class BoardArray2D extends AbstractBoard {
	private static int[][] arr;

	@Override
	public void reset() {
		arr = new int[size[1]][size[0]];
		int index = 1;
		for (int i = 0; i < size[1]; i++) {
			for (int j = 0; j < size[0]; j++) {
				arr[i][j] = index;
				index++;
			}
		}
		arr[size[1] - 1][size[0] - 1] = -1;
		coordinatesOfSpace[0] = size[0] - 1;
		coordinatesOfSpace[1] = size[1] - 1;
	}

	@Override
	public int cell(int x, int y) {

		try {
			if (x >= 0 && x < size[0] && y >= 0 && y < size[1]) {
				return arr[y][x];
			}
		} catch (IndexOutOfBoundsException exception) {
			System.exit(0);
		}
		return 0;
	}

	@Override
	public void readFromFile(String nameOfFile) {
		File file = new File(nameOfFile); // Change this to your file name

		try {
			calculateXandY(file);
			arr = new int[size[1]][size[0]];
			Scanner fileReader = new Scanner(file);
			int result = 0;
			while (fileReader.hasNext()) {
				for (int i = 0; i < size[1]; ++i) {
					for (int j = 0; j < size[0]; ++j) {
						String word = fileReader.next();
						if (word.equals("bb")) {
							result = -1;
							coordinatesOfSpace[0] = j;
							coordinatesOfSpace[1] = i;
						} else {
							result = Integer.parseInt(word);
						}
						arr[i][j] = result;
					}
				}
			}
			fileReader.close();
		} catch (IOException e) {
			System.out.printf("IOException\n");
		}

	}

	@Override
	public void move(final char direction) {
		int temp, x, y;
		x = coordinatesOfSpace[0];
		y = coordinatesOfSpace[1];
		if (direction == 'L' || direction == 'l') {
			if (isValid('L')) {
				temp = arr[y][x - 1];
				arr[y][x - 1] = arr[y][x];
				arr[y][x] = temp;
				coordinatesOfSpace[0]--;
			} 
		} else if (direction == 'R' || direction == 'r') {
			if (isValid('R')) {
				temp = arr[y][x + 1];
				arr[y][x + 1] = arr[y][x];
				arr[y][x] = temp;
				coordinatesOfSpace[0]++;
			} 
		} else if (direction == 'U' || direction == 'u') {
			if (isValid('U')) {
				temp = arr[y - 1][x];
				arr[y - 1][x] = arr[y][x];
				arr[y][x] = temp;
				coordinatesOfSpace[1]--;
			} 
		} else if (direction == 'D' || direction == 'd') {
			if (isValid('D')) {
				temp = arr[y + 1][x];
				arr[y + 1][x] = arr[y][x];
				arr[y][x] = temp;
				coordinatesOfSpace[1]++;
			} 
		}	
		if(isValid(direction)){
			_lastMove = direction;
			_numberOfMoves++;
			System.out.println("Moved to " + direction);
        }
	}
}