#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;

  Node(int val = 0) : data(val), next(nullptr) {}
  Node(int val, Node *tempNext) : data(val), next(tempNext) {}
};

class LinkedList
{
  Node *head;
  Node *tail;
  int size;

public:
  LinkedList() : head(nullptr), tail(nullptr), size(0)
  {
  }

  void addFirst(int val)
  {
    Node *newest = new Node(val);
    newest->next = head;
    head = newest;
    if (size == 0)
    {
      tail = head;
    }
    size++;
  }
  void insert(int val)
  {
    Node *newest = new Node(val);
    if (head == nullptr)
    {
      head = newest;
      tail = newest;
      size++;
    }
    else if (newest->data < head->data)
    {
      addFirst(val);
    }
    else
    {
      Node *c = head;
      while (c->next != nullptr && newest->data > c->next->data)
      {
        c = c->next;
      }

      if (c->next == nullptr)
      {
        addLast(val);
      }
      else
      {
        newest->next = c->next;
        c->next = newest;
      }
      size++;
    }
  }

  void addLast(int val)
  {
    Node *newest = new Node(val);
    if (size == 0)
      head = newest;
    else
      tail->next = newest;
    tail = newest;
    size++;
  }

  void removeFirst()
  {
    if (head != nullptr)
    {

      head = head->next;
      size--;
      if (size == 0)
      {
        tail = nullptr;
      }
    }
  }

  void remove(int val)
  {
    Node *temp = head;
    if (head != nullptr)
    {
      if (head->data == val)
      {
        removeFirst();
      }
      else
      {
        Node *c = head;
        while (c->next != nullptr && c->next->data != val)
        {
          c = c->next;
        }
        if (c->next != nullptr)
        {
          Node *temp = c->next;
          c->next = temp->next;
          size--;
        }
      }
    }
  }

  void removeLast()
  {
    if (head != nullptr)
    {
      if (head->next == nullptr)
      {
        head = nullptr;
        tail = nullptr;
        size--;
      }
      else
      {
        Node *secondLast = head;
        Node *last = head->next;
        while (last->next != nullptr)
        {
          secondLast = secondLast->next;
          last = last->next;
        }
        secondLast->next = nullptr;
        tail = secondLast;
        size--;
      }
    }
  }

  void display()
  {
    Node *temp = head;
    cout << "head = " << head->data << ", tail = " << tail->data << "\n";
    while (temp != nullptr)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main()
{

  LinkedList l;
  l.insert(6);
  l.insert(9);
  l.insert(1);
  l.insert(3);
  l.insert(7);
  cout << "Current Linked List: ";
  l.display();

  cout << "Deleting First: ";
  l.remove(3);
  l.display();

  cout << "Deleting 1: ";
  l.remove(1);
  l.display();
}