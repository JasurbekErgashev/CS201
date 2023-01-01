#include <iostream>
#include <stack>
 
using namespace std;
 
struct Node {
    char data;
    Node* next;
    Node(int data) {
        this->data = data;
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
    void insertAtLast(char data) {
        Node* newNode = new Node(data);
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
        Node* temp = head;
        while (temp) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    bool isPalindrome() {
        Node* slow = head;
        stack<int> s;
        while (slow != NULL) {
            s.push(slow->data);
            slow = slow->next;
        }
        while (head != NULL) {
            int i = s.top();
            s.pop();
            if (head->data != i) {
                return false;
            }
            head = head->next;
        }
        return true;
    }
};
 
 
int main() {
    List w;
    cout << "Enter a word: ";
    string word; cin >> word;
    for (int i = 0; i < word.size(); i++) {
        w.insertAtLast(word[i]);
    }
    cout << "isPalindrome: ";
    if (w.isPalindrome()) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
 
    return 0;
}
