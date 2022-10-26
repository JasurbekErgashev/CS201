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
    void printAll() {
        Node* track = head;
        while (track != NULL) {
            cout << track->data << endl;
            track = track->next;
        }
    };
};
int main(){
    List obj;
    //obj.insertAtLast(6);
    //obj.insertAtLast(8);
    //obj.insertAtLast(18);
    //obj.insertAtLast(22);
    //obj.insertAtLast(25);
    for (int i = 0; i < 10; i++) {
        obj.insertAtLast(i + 10);
    }
    cout << "Output is " << endl;
    obj.printAll();
    return 0;
}
