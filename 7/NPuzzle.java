public class NPuzzle {
	private static int[] border = new int [2];
	private static int [] coordinatesOfSpace = new int [2];
	private static int [][] arr;
	public NPuzzle(int _number1,int _number2) {
		arr = new int [_number1][_number2];
		int index = 1;
		for(int i = 0;i < _number1; i++) {
			for(int j = 0;j < _number2; j++) {
				arr[i][j] = index;
				index++;
			}
		}
		border[0] = _number2;
		border[1] = _number1;
		arr[border[1]-1][border[0]-1] = -1;
		coordinatesOfSpace[0] = border[0]-1;
		coordinatesOfSpace[1] = border[1]-1;
	}
	public NPuzzle(int _number) {
		int [][] puzzle = new int [_number][_number];
		int index = 1;
		for(int i = 0;i < _number; i++) {
			for(int j = 0;j < _number; j++) {
				puzzle[i][j] = index;
				index++;
			}
		}
		border[0] = border[1] = _number;
		puzzle[border[1]][border[0]] = -1;
		coordinatesOfSpace[0] = border[0]-1;
		coordinatesOfSpace[1] = border[1]-1;
	}
	public void print() {
		for(int i = 0;i < border[1]; i++) {
			for(int j = 0;j < border[0]; j++) {
				System.out.printf("%3d ",arr[i][j]);
			}
			System.out.printf("\n");
		}
	}
	public boolean move(char direction) {
		int temp,x,y;
	    x=coordinatesOfSpace[0];
	    y=coordinatesOfSpace[1];
	    if(direction == 'L' || direction == 'l'){
	        if(isValid('L')){
	            temp = arr[y][x-1];
	            arr[y][x-1] = arr[y][x];
	            arr[y][x] = temp;
	            coordinatesOfSpace[0]--;
	        }else{
	            return false;
	        }
	    }else if(direction == 'R' || direction == 'r'){
	        if(isValid('R')){
	            temp = arr[y][x+1];
	            arr[y][x+1] = arr[y][x];
	            arr[y][x] = temp;
	            coordinatesOfSpace[0]++;
	        }else{
	            return false;
	        }
	    }else if(direction == 'U' || direction == 'u'){
	        if(isValid('U')){
	            temp = arr[y-1][x];
	            arr[y-1][x] = arr[y][x];
	            arr[y][x]= temp;
	            coordinatesOfSpace[1]--;
	        }else{
	            return false;
	        }
	    }else if(direction == 'D' || direction == 'd'){
	        if(isValid('D')){
	            temp = arr[y+1][x];
	            arr[y+1][x] = arr[y][x];
	            arr[y][x] = temp;
	            coordinatesOfSpace[1]++;
	        }else{
	            return false;
	        }
	    }
	    return true;
	}
	public boolean isValid(char direction) {
	    if((direction == 'L' || direction == 'l') && coordinatesOfSpace[0]-1 >= 0 && arr[coordinatesOfSpace[1]][coordinatesOfSpace[0] - 1] != 0){
	        return true;
	    }else if((direction == 'R' || direction == 'r') && coordinatesOfSpace[0]+1 < border[0] && arr[coordinatesOfSpace[1]][coordinatesOfSpace[0] + 1] != 0){
	        return true;
	    }else if((direction == 'U' || direction == 'u') &&  coordinatesOfSpace[1]-1 >= 0 && arr[coordinatesOfSpace[1]- 1][coordinatesOfSpace[0]] != 0){
	        return true;
	    }else if((direction == 'D' || direction == 'd') &&  coordinatesOfSpace[1]+1 < border[1] && arr[coordinatesOfSpace[1] + 1][coordinatesOfSpace[0]] != 0){
	        return true;
	    }else {
	        return false;
	    }
	}
	
}