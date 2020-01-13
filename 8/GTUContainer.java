public class GTUContainer<T> {
    protected T[] arr;
    protected Class<T> _type;
    protected int _size;
    protected int capacity;

    public GTUContainer(Class<T> type) {

        this._type = type;
        clear();
    }

    /**
     * GTUIteratorSet implementation by override GTUIterator functions
     */

    class GTUIteratorSet implements GTUIterator<T> {

        public int position = 0;

        @Override
        public boolean hasNext() {
            if (position < _size)
                return true;
            return false;
        }

        @Override
        public T next() {
            return arr[position++];
        }

        /**
         * Extra function 
         */

        @Override
        public T current() {
            return arr[position];
        }

        @Override
        public int index(){
            return position;
        }

    }

    public boolean contains(Object o) {
        for (int i = 0; i < this._size; i++) {
            if (arr[i] == o) {
                return true;
            }
        }
        return false;
    }

    public GTUIterator<T> iterator() {
        return new GTUIteratorSet();
    }

    void insert(T inserted)
    {
        
        try {
            
            if(inserted.getClass() != _type){
                throw new IllegalArgumentException("Wrong argument");
            }

            if (_size +1 >= capacity) {
                capacity *= 2;
                T[] dest = (T[]) java.lang.reflect.Array.newInstance(_type,capacity);
                for(int j=0; j<_size; j++)
					dest[j] = arr[j];
                arr = dest;

            }
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.printf("ArrayIndexOutOfBoundsException");
        } catch (IllegalArgumentException exception){
            System.out.printf("Wrong argument");
        }
    }

    public boolean empty(){
        return this._size == 0;
    }

    public int size(){
        return this._size;
    }

    public int max_size(){
        return capacity;
    }
    
    public void clear(){
        this._size = 0;
        capacity = 1;

        /**
         * Creates a new array with the specified type and length at runtime
         */
        this.arr = (T[]) java.lang.reflect.Array.newInstance(_type, capacity);
    }

}