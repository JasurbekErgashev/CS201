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
    void traverse();
    bool insertIndexBased(int index, int data);
    int search(int data);
    void deleteFirst();
    int countNodes();
   
};
// a
void List::traverse() {
    Node* track = head;
    while (track != NULL) {
        cout << track->data << " ";
        track = track->next;
    }
}
// b
bool List::insertIndexBased(int index, int data) {
    if (index < 0) return false;
    int currIndex = 1;
    Node* currNode = head;
    while (currNode && index > currIndex) {
        currNode = currNode->next;
        currIndex++;
    }
    if (index > 0 && currNode == NULL) return false;
    Node* newNode = new Node;
    newNode->data = data;
    if (index == 0) {
        newNode->next = head;
        head = newNode;
    }
    else {
        newNode->next = currNode->next;
        currNode->next = newNode;
    }
    return true;
}
// c
int List::search(int data) {
    Node* currNode = head;
    int currIndex = 0;
    while (currNode && currNode->data != data) {
        currNode = currNode->next;
        currIndex++;
    }
    if (currNode)
        return currIndex;
    return -1;
}
// d
void List::deleteFirst() {
    if (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
// e
int List::countNodes() {
    int numNodes = 0;
    Node* start = head;
    while (start != NULL) {
        start = start->next;
        numNodes++;
    }
    return numNodes;
}
 
int main() {
    List obj;
    for (int i = 1; i <= 10; i++) {
        obj.insertAtLast(i + 10);
    }
    cout << "Traversing: ";
    obj.traverse();
 
    cout << "\n\n";
 
    cout << "Inserting at index: ";
    cout  << std::boolalpha << obj.insertIndexBased(3, 5) << endl;
    obj.traverse();
 
    cout << "\n\n";
 
    cout << "Searching: ";
    cout << obj.search(5);
 
    cout << "\n\n";
 
    cout << "Deleting the first Node: ";
    obj.deleteFirst();
    obj.traverse();
 
    cout << "\n\n";
 
    cout << "Counting the number of Nodes: ";
    cout << obj.countNodes() << endl;
 
    return 0;
}
