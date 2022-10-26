#include <iostream>
using std::cout;
using std::cin;
using std::endl;
struct Node {
    int data;
    Node* next;
    Node() {
        next = NULL;
    }
};
void printRec(Node* curr) {
    if (curr) {
        cout << curr->data << endl;
        printRec(curr->next);
    }
}
class List {
    Node* head, * last;
public:
    List() { head = NULL; last = NULL; };
    void insertAtLast(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        if (!head) {
            head = newNode;
            last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
    }
    void insertAtFront(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    void printAll() {
        printRec(head);
    };
};
int main(){
    List obj;
    for (int i = 0; i < 10; i++) {
        obj.insertAtFront(i + 10);
    }
    cout << "Output is " << endl;
    obj.printAll();
    return 0;
}
