/**
 * Abstract GTUContainer<T> template class
 * 
 * @param <T>
 */
public abstract class GTUContainer<T> {
    /**
     * Array representation
     */
    protected T[] arr;
    /**
     * Class type of any GTUContainer<T> class
     */
    protected Class<T> _type;
    /**
     * Size of any GTUContainer<T> class that can take values
     */
    protected int _size;
    /**
     * Capacity any GTUContainer<T> class that increases 2^n
     */
    protected int capacity;

    /**
     * Constructor any GTUContainer<T> class
     * 
     * @param type
     */
    public GTUContainer(Class<T> type) {

        this._type = type;
        clear();
    }

    /**
     * GTUIteratorSet implementation by override GTUIterator functions
     */
    class GTUIteratorContainer implements GTUIterator<T> {
        /**
         * Position representation of GTUIterator
         */
        protected int position = 0;

        /**
         * Returns a boolean value depending on the existence of a value at the next
         * index of iterator.
         * 
         * @return if there is an element or not
         */
        @Override
        public boolean hasNext() {
            if (position < _size)
                return true;
            return false;
        }

        /**
         * Returns value depending on the existence of a value at the next of iterator.
         * 
         * @return value of next index
         */
        @Override
        public T next() {
            return arr[position++];
        }

        /**
         * Returns a boolean value depending on the existence of a value at the current
         * of iterator.
         * 
         * @return value of current index
         */

        public T current() {
            return arr[position];
        }

        /**
         * Returns the position of the iterator
         * 
         * @return position of iterator
         */

        public int index() {
            return position;
        }

    }

    /**
     * Method for create new iterator
     * 
     * @return new iterator
     */
    public GTUIterator<T> iterator() {
        return new GTUIteratorContainer();
    }

    /**
     * Method that returns if GTUContainer<T> contains given "o" object
     * 
     * @param o Object that is given
     * @return If GTUContainer<T> contains given "o" object
     */
    public boolean contains(Object o) {
        for (int i = 0; i < this._size; i++) {
            if (arr[i] == o) {
                return true;
            }
        }
        return false;
    }

    @SuppressWarnings("unchecked")
    /**
     * Insert function of GTUContainer<T>
     * 
     * @param inserted value that will be inserted
     */
    void insert(T inserted) {

        try {

            if (inserted.getClass() != _type) {
                throw new IllegalArgumentException("Wrong argument");
            }

            if (_size + 1 >= capacity) {
                capacity *= 2;

                T[] dest = (T[]) java.lang.reflect.Array.newInstance(_type, capacity);
                for (int j = 0; j < _size; j++)
                    dest[j] = arr[j];
                arr = dest;

            }
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.printf("ArrayIndexOutOfBoundsException");
        } catch (IllegalArgumentException exception) {
            System.out.printf("Wrong argument");
        }
    }

    /**
     * Returns if GTUContainer<T> empty or not
     * 
     * @return boolean value of being empty of GTUContainer<T>
     */
    public boolean empty() {
        return this._size == 0;
    }

    /**
     * Returns size of GTUContainer<T>
     * 
     * @return Integer size value
     */
    public int size() {
        return this._size;
    }

    /**
     * Maximum capacity that can take GTUContainer<T>
     * 
     * @return Integer value of capacity
     */
    public int max_size() {
        return capacity;
    }

    /**
     * Erase value that points of iterator
     * 
     * @param iter Iterator that points to somewhere at the GTUContainer<T>
     */
    void erase(GTUIterator<T> iter) {
        boolean isAlreadyInserted = false;
        for (GTUIterator<T> iter_temp = this.iterator(); iter_temp.hasNext(); iter_temp.next()) {
            if (iter_temp.current() == iter.current()) {
                for (GTUIterator<T> iter2 = iter_temp; iter2.hasNext(); iter2.next()) {
                    arr[iter2.index()] = arr[iter2.index() + 1];
                }
                isAlreadyInserted = true;
            }
        }
        if (isAlreadyInserted)
            this._size--;
        if (this._size <= this.capacity / 2)
            this.capacity /= 2;
    }

    @SuppressWarnings("unchecked")

    /**
     * Method that make GTUContainer<T> empty
     */
    public void clear() {
        this._size = 0;
        capacity = 1;

        /**
         * Creates a new array with the specified type and length at runtime
         */
        this.arr = (T[]) java.lang.reflect.Array.newInstance(_type, capacity);
    }

}