public interface GTUIterator<T> {
    /**
     * Index-wise location of the iterator.
     */
    int position = 0;

    /**
     * Returns a boolean value depending on the existence of a value at the next
     * index of iterator.
     * 
     * @return if there is an element or not
     */
    boolean hasNext();

    /**
     * Returns a boolean value depending on the existence of a value at the next of
     * iterator.
     * 
     * @return value of next index
     */

    T next();

    /**
     * Returns a boolean value depending on the existence of a value at the current of
     * iterator.
     * 
     * @return value of current index
     */
    T current();

    int index();
}