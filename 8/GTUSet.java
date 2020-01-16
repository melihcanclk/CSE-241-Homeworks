/**
 * GTUSet class that represent STL set of C++
 * 
 * @param <T>
 */
public class GTUSet<T extends Comparable<T>> extends GTUContainer<T> {
    /**
     * GTUSet constructor that takes parameter of Class type
     * 
     * @param type Type of class that templates
     */
    GTUSet(Class<T> type) {
        super(type);
    }

    /**
     * Private method for insert value accenting order
     * 
     * @param value Value that will be insert
     */
    private void insertSorted(T value) {
        int i;
        if (_size == 0) {
            arr[0] = value;
        } else {
            for (i = _size - 1; (i >= 0 && value.compareTo(arr[i]) == -1); i--)
                arr[i + 1] = arr[i];

            arr[i + 1] = value;
        }

        this._size++;
    }

    /**
     * Insert function that insert value to the GTUSet without using
     * GTUIterator<T>
     * 
     * @param inserted Value that will be inserted
     */
    public void insert(T inserted) {
        super.insert(inserted);
        insertSorted(inserted);
    }

}