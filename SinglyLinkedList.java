package javaapplication1;

/**
 *
 * @author Walaa Alfahmi
 */
class Node<E> {

    E data;
    Node next;

    public Node() {
        next = null;
    }

    public Node(E e) {
        data = e;
        next = null;
    }
}

public class SinglyLinkedList<E> {

    Node head;
    Node tail;
    int size = 0;

    public SinglyLinkedList() {
        head = null;
        tail = null;
        size = 0;
    }

    public void addFirst(E e) {
        Node newest = new Node(e);
        newest.next = head;
        head = newest;
        if (size == 0) {
            tail = head;
        }
        size++;
    }

    public void insert(Integer e) {
        Node newest = new Node(e);
        if (head == null) {
            head = newest;
            tail = newest;
            size++;
        } else if ((Integer) newest.data < (Integer) head.data) {
            addFirst((E) e);
        } else {
            Node c = head;
            while (c.next != null && (Integer) newest.data > (Integer) c.next.data) {
                c = c.next;
            }
            if (c.next == null) {
                addLast((E) e);
            } else {
                newest.next = c.next;
                c.next = newest;
            }
            size++;
        }

    }

    public void addLast(E e) {
        Node newest = new Node(e);
        if (size == 0) {
            head = newest;
        } else {
            tail.next = newest;
        }
        tail = newest;
        size++;
    }

    public void removeFirst() {
        if (head != null) {

            head = head.next;
            size--;
            if (size == 0) {
                tail = null;
            }
        }
    }

    public void remove(E e) {
        if (head != null) {
            if (head.data == e) {
                removeFirst();
            } else if (tail.data == e) {
                removeLast();
            } else {
                Node c = head;
                while (c.next != null && c.next.data != e) {
                    c = c.next;
                }
                if (c.next != null) {
                    Node temp = c.next;
                    c.next = temp.next;
                    size--;
                }
            }
        }
    }

    public void removeLast() {
        if (head != null) {
            if (head.next == null) {
                head = null;
                tail = null;
                size--;
            } else {
                Node secondLast = head;
                Node last = head.next;
                while (last.next != null) {
                    secondLast = secondLast.next;
                    last = last.next;
                }
                secondLast.next = null;
                tail = secondLast;
                size--;
            }
        }
    }

    public static void main(String[] args) {
        // TODO code application logic here
        SinglyLinkedList list = new SinglyLinkedList();
        list.insert(5);
        list.insert(1);
        list.insert(0);
        list.insert(7);
        list.insert(9);
        list.insert(2);

        Node c = list.head;
        list.remove(9);
        System.out.println("head: " + c.data);
        System.out.println("tail: " + list.tail.data);
        while (c != null) {
            System.out.println(c.data);
            c = c.next;
        }
    }

}
