/**
 * GTUVector class that represent STL vector of C++
 * @param <T>
 */
public class GTUVector<T> extends GTUContainer<T> {

    /**
     * GTUVector constructor that takes parameter of Class type
     * @param type Type of class that templates
     */
    GTUVector(Class<T> type) {
        super(type);
    }
/**
 * Insert function that insert value to the GTUVector without using GTUIterator<T>
 * @param inserted Value that will be inserted
 */
    public void insert(T inserted) {
        super.insert(inserted);
        arr[_size] = inserted;
        this._size++;
    }
    
/**
 * Insert function that insert value to the GTUVector with using GTUIterator<T>
 * @param iter Iterator that is pointing to anywhere of vector
 * @param inserted Value that will be inserted
 */
    void insert(GTUIterator<T> iter, T inserted) {
        int i;
        super.insert(inserted);
        for (i = _size - 1; (i >= 0 && arr[i] != iter.current()); i--)
            arr[i + 1] = arr[i];

        arr[i + 1] = inserted;
        this._size++;
    }

}