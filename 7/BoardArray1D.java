import java.util.Scanner;
import java.io.*;

public class BoardArray1D extends AbstractBoard{
    private int[] arr;
    @Override
	public void reset() {
		arr = new int[size[1] * size[0]];
		int index = 1;
		for (int i = 0; i < size[1]; i++) {
			for (int j = 0; j < size[0]; j++) {
				arr[size[0] * i + j] = index;
				index++;
			}
		}
        arr[(size[0] * size[1]) -1] = -1;
        coordinatesOfSpace[0] = size[0] - 1;
		coordinatesOfSpace[1] = size[1] - 1;
    }
    @Override
	public int cell(int x, int y) {

		try {
			if (x >= 0 && x <= size[0] && y >= 0 && y <= size[1]) {
				return arr[size[0] * y + x];
			}
		} catch (IndexOutOfBoundsException exception) {
			System.exit(0);
		}
		return 0;
    }
    public void readFromFile(String nameOfFile) {
		File file = new File(nameOfFile); // Change this to your file name

		try {
			calculateXandY(file);
			arr = new int[size[1] * size[0]];
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
						arr[size[0] * i + j] = result;
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
				temp = cell(x-1,y);
				arr[size[0] * y + x -1] = cell(x,y);
				arr[size[0] * y + x] = temp;
				coordinatesOfSpace[0]--;
			} 
		} else if (direction == 'R' || direction == 'r') {
			if (isValid('R')) {
				temp = cell(x+1,y);
				arr[size[0] * y + x +1] = cell(x,y);
				arr[size[0] * y + x] = temp;
				coordinatesOfSpace[0]++;
			} 
		} else if (direction == 'U' || direction == 'u') {
			if (isValid('U')) {
				temp = cell(x,y-1);
				arr[(size[0] * (y-1)) + x ] = cell(x,y);
				arr[size[0] * y + x] = temp;
				coordinatesOfSpace[1]--;
			} 
		} else if (direction == 'D' || direction == 'd') {
			if (isValid('D')) {
				temp = cell(x,y+1);
				arr[(size[0] * (y+1)) + x ] = cell(x,y);
				arr[size[0] * y + x ] = temp;
				coordinatesOfSpace[1]++;
			}
        }
        if(isValid(direction)){
            _lastMove = direction;
            _numberOfMoves++;
        }
        
	}
}