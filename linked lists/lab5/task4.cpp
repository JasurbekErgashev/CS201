#include <iostream>

using std::cout;
using std::endl;

struct Node {
  int data;
  Node *next;
  Node() { next = NULL; }
  Node(int data) {
    this->data = data;
    next = NULL;
  }
};

class List {
  Node *head, *last;

public:
  List() {
    head = NULL;
    last = NULL;
  }
  void insertAtLast(int data) {
    Node *newNode = new Node(data);
    if (!head) {
      head = newNode;
      last = newNode;
    } else {
      last->next = newNode;
      last = newNode;
    }
  }
  void printAll() {
    Node *track = head;
    while (track != NULL) {
      cout << track->data << " ";
      track = track->next;
    }
  }
  bool isInList(Node *ptr, int data) {
    while (ptr) {
      if (ptr->data == data) {
        return true;
      }
      ptr = ptr->next;
    }
    return false;
  }
  List intersectList(List obj) {
    Node *curr1 = head, *curr2 = obj.head;
    List newList;
    while (curr1) {
      if (isInList(curr2, curr1->data) &&
          !isInList(newList.head, curr1->data)) {
        newList.insertAtLast(curr1->data);
      }
      curr1 = curr1->next;
    }
    return newList;
  }
};

int main() {
  List obj1, obj2;
  obj1.insertAtLast(5);
  obj1.insertAtLast(15);
  obj1.insertAtLast(25);
  obj1.insertAtLast(35);
  obj1.insertAtLast(45);
  obj1.insertAtLast(5);
  obj1.insertAtLast(5);
  obj2.insertAtLast(15);
  obj2.insertAtLast(25);
  obj2.insertAtLast(4);
  obj2.insertAtLast(5);
  obj2.insertAtLast(51);
  List obj3 = obj1.intersectList(obj2);
  obj3.printAll();
  cout << endl;
  return 0;
}
