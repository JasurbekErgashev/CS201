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
 
class List {
    Node* head, * last;
public:
    List() {
        head = NULL;
        last = NULL;
    }
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
    void merge(List obj) {
        last->next = obj.head;
    }
    void printAll() {
        Node* track = head;
        while (track != NULL) {
            cout << track->data << " ";
            track = track->next;
        }
    }
};
 
int main() {
    List ListA;
    ListA.insertAtLast(18);
    ListA.insertAtLast(25);
    ListA.insertAtLast(17);
 
    List ListB;
    ListB.insertAtLast(13);
    ListB.insertAtLast(28);
    ListB.insertAtLast(14);
 
    ListA.merge(ListB);
    ListA.printAll();
   
    return 0;
}
