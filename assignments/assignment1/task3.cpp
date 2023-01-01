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
void selectionSortList(Node* head){
    Node* curr = head;
    while (curr) {
        Node* min = curr;
        Node* r = curr->next;
        while (r) {
            if (min->data > r->data)
                min = r;
            r = r->next;
        }
        int x = curr->data;
        curr->data = min->data;
        min->data = x;
        curr = curr->next;
    }
}
void print_linked_list(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main() {
    srand(time(0));
    Node* head = NULL;
    Node* last = head;
    int count = 0;
    while (count < 10) {
        Node* newNode = new Node(rand());
        if (!head) {
            head = newNode;
            last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
        count++;
    }
    cout << "original: ";
    print_linked_list(head);
    selectionSortList(head);
    cout << "sorted: ";
    print_linked_list(head);
    return 0;
}
