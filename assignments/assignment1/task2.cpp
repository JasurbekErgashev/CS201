#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};
class LinkedList {
public:
    Node* head;
    Node* sorted;
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void insertionSortList(Node* headref){
        sorted = NULL;
        Node* curr = headref;
        while (curr) {
            Node* next = curr->next;
            sortedInsert(curr);
            curr = next;
        }
        head = sorted;
    }
    void sortedInsert(Node* newNode) {
        if (!sorted || sorted->data >= newNode->data) {
            newNode->next = sorted;
            sorted = newNode;
        }
        else {
            Node* curr = sorted;
            while (curr->next && curr->next->data < newNode->data) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }
    void print(Node* head) {
        Node* start = head;
        while (start) {
            cout << start->data << " ";
            start = start->next;
        }
        cout << endl;
    }
};
int main() {
    srand(time(0));
    LinkedList list{};
    list.head = NULL;
    int count = 0;
    while (count < 10) {
        list.push(rand());
        count++;
    }
    cout << "original: ";
    list.print(list.head);
    list.insertionSortList(list.head);
    cout << "sorted: ";
    list.print(list.head);
    return 0;
}
