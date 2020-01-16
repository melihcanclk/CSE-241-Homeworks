import java.lang.Exception;

/**
 * Exception class that warn if a value inserted or not
 */
class AlreadyInsertedException extends Exception {

    /**
     *
     */
    private static final long serialVersionUID = 6195479895190168564L;

    AlreadyInsertedException(String errorMessage) {
        super(errorMessage);
    }
}
