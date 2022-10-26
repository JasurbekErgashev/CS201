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
  int findMiddleNode() {
    Node *middle = head;
    Node *end = head;
    while (end != NULL && end->next != NULL) {
      middle = middle->next;
      end = end->next->next;
    }
    return middle->data;
  }
};

int main() {
  List obj;
  obj.insertAtLast(7);
  obj.insertAtLast(1);
  obj.insertAtLast(9);
  obj.insertAtLast(3);
  obj.insertAtLast(5);
  obj.insertAtLast(15);
  cout << "Middle node is: " << obj.findMiddleNode() << endl;
  return 0;
}
