
#include <iostream>

using std::cout;

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
  void CopyList(List obj) {
    Node *first = obj.head;
    while (obj.head) {
      Node *newNode = new Node(obj.head->data);
      if (!head) {
        head = newNode;
        last = newNode;
      } else {
        last->next = newNode;
        last = newNode;
      }
      obj.head = obj.head->next;
    }
    obj.head = first;
  }
};

int main() {
  List obj;
  obj.insertAtLast(3);
  obj.insertAtLast(1);
  obj.insertAtLast(2);
  obj.insertAtLast(5);
  obj.insertAtLast(15);
  List obj2;
  obj2.CopyList(obj);
  obj.insertAtLast(18);
  obj.insertAtLast(13);
  obj2.printAll();
  return 0;
}
