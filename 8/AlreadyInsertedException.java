import java.lang.Exception;

class AlreadyInsertedException extends Exception { 

    public AlreadyInsertedException(String errorMessage) {
        super(errorMessage);
    }
}