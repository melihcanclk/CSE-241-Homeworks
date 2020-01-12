import java.lang.Exception;

class IllegalArgumentException extends Exception { 

    public IllegalArgumentException(String errorMessage) {
        super(errorMessage);
    }
}