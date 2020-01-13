public class GTUVector<T> extends GTUContainer<T> {

    GTUVector(Class<T> type) {
        super(type);
    }

    public void insert(T inserted) {
        super.insert(inserted);
        arr[_size] = inserted;
        this._size++;
    }

    void insert(GTUIterator<T> iter, T inserted) {
        int i;
        super.insert(inserted);
        for (i = _size - 1; (i >= 0 && arr[i] != iter.current()); i--)
            arr[i + 1] = arr[i];

        arr[i + 1] = inserted;
        this._size++;
    }

}