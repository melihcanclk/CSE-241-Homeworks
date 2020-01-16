import java.util.Iterator;

public interface GTUIterator<T> extends Iterator<T> {
    /**
     * Index-wise location of the iterator
     */
    int position = 0;

    /**
     * Returns a boolean value depending on the existence of a value at the next
     * index of iterator.
     * 
     * @return if there is an element or not
     */
    @Override
    public boolean hasNext();

    /**
     * Returns value depending on the existence of a value at the next of
     * iterator.
     * 
     * @return value of next index
     */
    @Override
    T next();

    /**
     * Returns a boolean value depending on the existence of a value at the current
     * of iterator.
     * 
     * @return value of current index
     */
    T current();

    /**
     * Returns the position of the iterator
     * 
     * @return position of iterator
     */
    int index();
}