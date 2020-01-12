public class Main {
    public static void main(String[] args) {
        GTUSet<Integer> a = new GTUSet<Integer>(Integer.class);
        GTUVector<Character> b = new GTUVector<Character>(Character.class);
        a.insert(5);
        a.insert(6);
        a.insert(3);
        a.insert(156);

        b.insert('a');
        b.insert('c');
        b.insert('y');
        b.insert('j');
        b.insert('i');

        GTUIterator<Integer> itr = a.iterator();
        print(itr);
        System.out.println();
        GTUIterator<Character> itr2 = b.iterator();
        itr2 = b.iterator();

        print(itr2);

        System.out.println();
        System.out.printf("Set contains %d : %s\n", 3, a.contains(3));
        System.out.printf("Set contains %d : %s\n", 7, a.contains(7));

        itr2 = b.iterator();
        itr2.next();
        b.insert(itr2, 'g');

        itr2 = b.iterator();
        print(itr2);
        System.out.println();

        itr2 = b.iterator();
        itr2.next();
        itr2.next();
        itr2.next();
        b.insert(itr2, 'u');

        itr2 = b.iterator();
        print(itr2);
        System.out.println();

        itr2 = b.iterator();
        b.insert(itr2, 'f');

        itr2 = b.iterator();
        print(itr2);
        System.out.println();
        a.insert(24);
        itr = a.iterator();
        itr.next();
        itr.next();
        a.erase(itr);
        itr = a.iterator();
        print(itr);
        System.out.println();

        itr = a.iterator();
        itr.next();
        itr.next();
        a.insert(2);
        itr = a.iterator();
        print(itr);
        System.out.println();
        a.clear();
        print(itr);
        System.out.println();
    }

    public static <T> void print(GTUIterator<T> itr) {
        while (itr.hasNext()) {
            System.out.printf("%s ", itr.next());
        }
    }

}
