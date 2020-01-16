public class Main {
    public static void main(String[] args) {
        GTUSet<Integer> a = new GTUSet<Integer>(Integer.class);
        GTUVector<Character> b = new GTUVector<Character>(Character.class);
        GTUIterator<Integer> itr = a.iterator();
        GTUIterator<Character> itr2 = b.iterator();

        a.insert(5);
        a.insert(6);

        print(itr);
        specs(a);

        a.insert(3);
        a.insert(156);

        itr = a.iterator();
        print(itr);
        specs(a);

        b.insert('a');
        b.insert('c');

        print(itr2);
        specs(b);

        b.insert('y');
        b.insert('j');
        b.insert('i');

        itr2 = b.iterator();
        print(itr2);
        specs(b);

        System.out.printf("%s contains %d : %s\n", a.getClass().getName(), 3, a.contains(3));
        System.out.printf("%s contains %d : %s\n", a.getClass().getName(), 7, a.contains(7));

        System.out.printf("%s contains %s : %s\n", b.getClass().getName(), 'y', b.contains('y'));
        System.out.printf("%s contains %s : %s\n", b.getClass().getName(), 'p', b.contains('p'));

        itr2 = b.iterator();
        itr2.next();
        b.insert(itr2, 'g');

        itr2 = b.iterator();
        print(itr2);
        specs(b);

        itr2 = b.iterator();
        itr2.next();
        itr2.next();
        itr2.next();
        b.insert(itr2, 'u');

        itr2 = b.iterator();
        print(itr2);
        specs(b);

        itr2 = b.iterator();
        b.insert(itr2, 'f');

        itr2 = b.iterator();
        print(itr2);
        specs(b);

        a.insert(24);
        itr = a.iterator();
        itr.next();
        itr.next();
        a.erase(itr);
        itr = a.iterator();
        print(itr);
        specs(a);

        itr = a.iterator();
        itr.next();
        itr.next();
        a.insert(2);
        itr = a.iterator();
        print(itr);
        specs(a);

        a.clear();
        itr = a.iterator();
        print(itr);
        specs(a);

        b.clear();
        itr2 = b.iterator();
        print(itr2);
        specs(b);

    }

    /**
     * Static method for print array
     * 
     * @param <T> Type of iterator
     * @param itr Iterator for print GTUContainer<T>
     */
    public static <T> void print(GTUIterator<T> itr) {

        while (itr.hasNext()) {
            System.out.printf("%s ", itr.next());
        }

        System.out.println();
        System.out.println();
    }

    /**
     * Static method for test array with specifications
     * 
     * @param <T>       Type of iterator
     * @param container Iterator for print GTUContainer<T>
     */
    public static <T> void specs(GTUContainer<T> container) {

        System.out.println(container.getClass().getName());
        System.out.printf("Size of Set: %d\n", container.size());
        System.out.printf("Max size of Set: %d\n", container.max_size());
        System.out.printf("Is this Set Empty: %s\n", container.empty());

        System.out.println();
    }

}
