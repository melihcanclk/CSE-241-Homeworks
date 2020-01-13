
public class GTUSet<T extends Comparable<T>> extends GTUContainer<T> {

    GTUSet(Class<T> type) {
        super(type);
    }

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

    public void insert(T inserted) {
        super.insert(inserted);
        insertSorted(inserted);
    }

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
   
}