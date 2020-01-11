import java.util.Scanner;
import java.io.*;
import java.util.Arrays;

public class BoardArray2D {
	private static int[] size = new int[2];
	private static int[] coordinatesOfSpace = new int[2];
	private static int[][] arr;

	public void calculateXandY(File f) throws IOException {
		Reader r = new BufferedReader(new InputStreamReader(new FileInputStream(f), "US-ASCII"));
		int countY = 0;
		int countX = 0;
		boolean flag = false;
		try {
			int intchar;
			while ((intchar = r.read()) != -1) {
				char ch = (char) intchar;
				if (intchar == '\n') {
					countY++;
					countX++;
					flag = true;
				} else if (ch == ' ') {
					countX++;
					flag = false;
				}
			}
		} finally {
			r.close();
			if (!flag) {
				countY++;
				countX++;
			}
			size[0] = countX / countY;
			size[1] = countY;
		}
	}

	public BoardArray2D() {
	}

	public BoardArray2D(final int _number1, final int _number2) {
		arr = new int[_number1][_number2];
		int index = 1;
		for (int i = 0; i < _number1; i++) {
			for (int j = 0; j < _number2; j++) {
				arr[i][j] = index;
				index++;
			}
		}
		size[0] = _number2;
		size[1] = _number1;
		arr[size[1] - 1][size[0] - 1] = -1;
		coordinatesOfSpace[0] = size[0] - 1;
		coordinatesOfSpace[1] = size[1] - 1;
	}

	public BoardArray2D(final int _number) {
		final int[][] puzzle = new int[_number][_number];
		int index = 1;
		for (int i = 0; i < _number; i++) {
			for (int j = 0; j < _number; j++) {
				puzzle[i][j] = index;
				index++;
			}
		}
		size[0] = size[1] = _number;
		puzzle[size[1]][size[0]] = -1;
		coordinatesOfSpace[0] = size[0] - 1;
		coordinatesOfSpace[1] = size[1] - 1;
	}

	public String toString() {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < arr.length; i++){
			for (int j = 0; j < arr[i].length; j++) {
				int index = cell(j,i);
				if(size[0] * size[1] <= 100){
					if(index == -1) {
						sb.append("bb");
					}else if(index / 10 == 0) {
						sb.append("0" + index);
					}else if(index/ 10 >= 1){
						sb.append(index);
					}
				}else if (size[0] * size[1] > 100 && size[0] * size[1] <= 1000){
					if(index == -1) {
						sb.append("bb");
					}else if(index / 10 == 0) {
						sb.append("00" + index);
					}else if(index / 100 == 0) {
						sb.append("0" + index);
					}else if(index/ 100 >= 1){
						sb.append(index);
					}
				}
				sb.append(" ");
			}
			sb.append("\n");;
		}
		return sb.toString();
	}

	public int cell(int x , int y){
		
		try{
			if(x>=0 && x< size[0] && y>=0 && y< size[1]){
				return arr[y][x];
			}
		}catch(IndexOutOfBoundsException exception){
			System.exit(0);
		}
		return 0;
	}
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

	public void print() {

	}

	public boolean move(final char direction) {
		int temp, x, y;
		x = coordinatesOfSpace[0];
		y = coordinatesOfSpace[1];
		if (direction == 'L' || direction == 'l') {
			if (isValid('L')) {
				temp = arr[y][x - 1];
				arr[y][x - 1] = arr[y][x];
				arr[y][x] = temp;
				coordinatesOfSpace[0]--;
			} else {
				return false;
			}
		} else if (direction == 'R' || direction == 'r') {
			if (isValid('R')) {
				temp = arr[y][x + 1];
				arr[y][x + 1] = arr[y][x];
				arr[y][x] = temp;
				coordinatesOfSpace[0]++;
			} else {
				return false;
			}
		} else if (direction == 'U' || direction == 'u') {
			if (isValid('U')) {
				temp = arr[y - 1][x];
				arr[y - 1][x] = arr[y][x];
				arr[y][x] = temp;
				coordinatesOfSpace[1]--;
			} else {
				return false;
			}
		} else if (direction == 'D' || direction == 'd') {
			if (isValid('D')) {
				temp = arr[y + 1][x];
				arr[y + 1][x] = arr[y][x];
				arr[y][x] = temp;
				coordinatesOfSpace[1]++;
			} else {
				return false;
			}
		}
		return true;
	}

	public boolean isValid(final char direction) {
		if ((direction == 'L' || direction == 'l') && coordinatesOfSpace[0] - 1 >= 0
				&& arr[coordinatesOfSpace[1]][coordinatesOfSpace[0] - 1] != 0) {
			return true;
		} else if ((direction == 'R' || direction == 'r') && coordinatesOfSpace[0] + 1 < size[0]
				&& arr[coordinatesOfSpace[1]][coordinatesOfSpace[0] + 1] != 0) {
			return true;
		} else if ((direction == 'U' || direction == 'u') && coordinatesOfSpace[1] - 1 >= 0
				&& arr[coordinatesOfSpace[1] - 1][coordinatesOfSpace[0]] != 0) {
			return true;
		} else if ((direction == 'D' || direction == 'd') && coordinatesOfSpace[1] + 1 < size[1]
				&& arr[coordinatesOfSpace[1] + 1][coordinatesOfSpace[0]] != 0) {
			return true;
		} else {
			return false;
		}
	}

}