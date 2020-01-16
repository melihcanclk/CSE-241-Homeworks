import java.io.*;

public abstract class AbstractBoard {
    protected int[] size = new int[2];
    protected int[] coordinatesOfSpace = new int[2];
    protected static int _numberOfBoards = 0;
    protected char _lastMove = 'S';
    protected static int _numberOfMoves = 0;

    public AbstractBoard(){
        _numberOfBoards++;
    }
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.getClass().getName() + "\n");
        for (int i = 0; i < size[1]; i++) {
            for (int j = 0; j < size[0]; j++) {
                int index = cell(j, i);
                stringAppend(index, sb);
                sb.append(" ");
            }
            sb.append("\n");
        }
        return sb.toString();
    }

    public void setSize(final int _number1, final int _number2) {

        size[0] = _number1;
        size[1] = _number2;
        reset();

    }

    public void setSize(final int _number) {

        size[0] = size[1] = _number;
        reset();

    }

    public void reset() {
    }

    public void readFromFile(String nameOfFile) {
    }

    public void writeToFile(String nameOfFile) throws IOException {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < size[1]; i++) {
            for (int j = 0; j < size[0]; j++) {
                int index = cell(j, i);
                stringAppend(index, sb);
                if (j != size[0] - 1)
                    sb.append(" ");
            }
            if (i != size[1] - 1)
                sb.append("\n");
        }
        String appendedString = sb.toString();
        FileWriter fileWriter = new FileWriter(nameOfFile);
        fileWriter.write(appendedString);
        fileWriter.close();
    }

    public void move(final char direction) {}

    protected void stringAppend(int index, StringBuilder sb) {
        if (size[0] * size[1] <= 100) {
            if (index == -1) {
                sb.append("bb");
            } else if (index / 10 == 0) {
                sb.append("0" + index);
            } else if (index / 10 >= 1) {
                sb.append(index);
            }
        } else if (size[0] * size[1] > 100 && size[0] * size[1] <= 1000) {
            if (index == -1) {
                sb.append("bb");
            } else if (index / 10 == 0) {
                sb.append("00" + index);
            } else if (index / 100 == 0) {
                sb.append("0" + index);
            } else if (index / 100 >= 1) {
                sb.append(index);
            }
        }
    }

    public int cell(int x, int y) {
        return 0;
    }

    public int numberOfBoards(){
        return _numberOfBoards;
    }

    public int lastMove(){
        return _lastMove;
    }
    public int numberOfMoves(){
        return _numberOfMoves;
    }

    protected void calculateXandY(File f) throws IOException {
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

    protected boolean isValid(final char direction) {

        if ((direction == 'L' || direction == 'l') && coordinatesOfSpace[0] - 1 >= 0
                && cell(coordinatesOfSpace[0] - 1, coordinatesOfSpace[1]) != 0) {
            return true;
        } else if ((direction == 'R' || direction == 'r') && coordinatesOfSpace[0] + 1 < size[0]
                && cell(coordinatesOfSpace[0] + 1, coordinatesOfSpace[1]) != 0) {
            return true;
        } else if ((direction == 'U' || direction == 'u') && coordinatesOfSpace[1] - 1 >= 0
                && cell(coordinatesOfSpace[0], coordinatesOfSpace[1] - 1) != 0) {
            return true;
        } else if ((direction == 'D' || direction == 'd') && coordinatesOfSpace[1] + 1 < size[1]
                && cell(coordinatesOfSpace[0], coordinatesOfSpace[1] + 1) != 0) {
            return true;
        } else {
            return false;
        }
    }

    public boolean isSolved() {
        int index = 1;
        for (int i = 0; i < size[1]; ++i) {
            for (int j = 0; j < size[0]; ++j) {
                int a = cell(j, i);
                if (index == a) {
                } else if (a == 0) {
                    index--;
                } else {
                    if (i != size[1] - 1 || j != size[0] - 1) {
                        return false;
                    }
                }
                index++;
            }
        }
        return true;
    }

    public boolean equals(AbstractBoard other) {
        if (this.size[0] == other.size[0] && this.size[1] == other.size[1]) {
            for (int i = 0; i < size[1]; ++i) {
                for (int j = 0; j < size[0]; ++j) {
                    if(this.cell(j,i) != other.cell(j, i)){
                        return false;
                    }
                }
            }
            return true;
        }
        return false;   
    }

    protected boolean isDiffTwo(AbstractBoard other) {
        int counter = 0;
        if (this.size[0] == other.size[0] && this.size[1] == other.size[1]) {
            for (int i = 0; i < size[1]; ++i) {
                for (int j = 0; j < size[0]; ++j) {
                    if(this.cell(j,i) != other.cell(j, i)){
                        counter++;
                    }
                }
            }
            if(counter == 2){
                return true;
            }else{
                return false;
            }
        }
        return false;   
    }
    
}