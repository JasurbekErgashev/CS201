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
void print_linked_list(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
void swap_node_values(Node* n1, Node* n2) {
    n1->data += n2->data;
    n2->data = n1->data - n2->data;
    n1->data = n1->data - n2->data;
}
void bubbleSortList(Node* head) {
    bool swapped;
    Node* left;
    Node* right = NULL;
    do {
        swapped = false;
        left = head;
        while (left->next != right) {
            if (left->data > left->next->data) {
                swap_node_values(left, left->next);
                swapped = true;
            }
            left = left->next;
        }
        right = left;
    } while (swapped);
}
int main(){
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
    bubbleSortList(head);
    cout << "sorted: ";
    print_linked_list(head);
    return 0;
}
