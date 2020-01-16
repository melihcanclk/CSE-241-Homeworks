import java.lang.Exception;
/**
* Class to check argument type
*/
class IllegalArgumentException extends Exception { 

    public IllegalArgumentException(final String errorMessage) {
        super(errorMessage);
    }
}
