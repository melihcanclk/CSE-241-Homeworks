import java.io.*;

public class BoardArray2D extends AbstractBoard {
	private static int[][] arr;

	/**
	 * Overrides reset() method from AbstractBoard
	 */
	@Override
	public void reset() {
		arr = new int[size[1]][size[0]];
		super.reset();
	}

	/**
	 * Overrides cell() method from AbstractBoard
	 */
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

	/**
	 * Overrides readFromFile() method from AbstractBoard
	 */
	@Override
	public void readFromFile(String nameOfFile) {
		try {
			arr = new int[size[1]][size[0]];
			super.readFromFile(nameOfFile);
		} catch (IOException e) {
			System.out.printf("IOException\n");
		}

	}

	/**
	 * Overrides assign() method from AbstractBoard
	 */
	@Override
	public void assign(int i, int j, int result) {

		arr[i][j] = result;
	}

}