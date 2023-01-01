#include <iostream>
 
using namespace std;
 
struct Node{
    int data;
    Node* next;
};
 
 
class LinkedListQueue{
public:
    LinkedListQueue() {
        queueFront = NULL;
        queueRear = NULL;
    };
    bool isEmptyQueue() {
        return queueFront == NULL;
    }
    bool isFullQueue() {
        return false;
    }
    void initializeQueue() {
        Node* temp;
        while (queueFront != NULL) {
            temp = queueFront;
            queueFront = queueFront->next;
            delete temp;
        }
        queueRear = NULL;
    }
    int front() {
        if (queueFront != NULL) {
            return queueFront->data;
        }
        throw "Queue is empty";
    };
    int back() {
        if (queueRear != NULL) {
            return queueRear->data;
        }
        throw "Queue is empty";
    };
    void addQueue(const int& queueElement) {
        Node* newNode = new Node;
        newNode->data = queueElement;
        newNode->next = NULL;
        if (queueFront == NULL) {
            queueFront = newNode;
            queueRear = newNode;
        }
        else {
            queueRear->next = newNode;
            queueRear = queueRear->next;
        }
    };
 
    void deleteQueue() {
        if (queueFront != NULL) {
            Node* temp = queueFront;
            queueFront = queueFront->next;
            if (queueFront == NULL)
                queueRear = NULL;
            delete temp;
        }else
            cout << "Queue is empty" << endl;  
    };
   
    LinkedListQueue(const LinkedListQueue& otherQueue) {
        Node* temp = otherQueue.queueFront;
        while (temp != NULL) {
            Node* newNode = new Node;
            newNode->data = temp->data;
            if (isEmptyQueue()) {
                queueFront = newNode;
            }
            else {
                queueRear = newNode;
            }
            queueRear = newNode;
            temp = temp->next;
        }
    };
 
    void printQueue() {
        if (!isEmptyQueue()) {
            Node* temp = queueFront;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        else
            cout << "An empty Queue can't be displayed";
    }
 
    ~LinkedListQueue() {
        Node* temp;
        while (queueFront != NULL) {
            temp = queueFront;
            queueFront = queueFront->next;
            delete temp;
        }
        queueRear = NULL;
    };
private:
    Node* queueFront;
    Node* queueRear;
};
 
 
int main(){
   
    LinkedListQueue q1;
 
    q1.addQueue(15);
    q1.addQueue(25);
    q1.addQueue(4);
    q1.addQueue(12);
    q1.addQueue(123);
    q1.addQueue(75);
    q1.addQueue(85);
    q1.addQueue(55);
 
    cout << q1.front() << endl;
 
    q1.deleteQueue();
    q1.printQueue();
    cout << endl;
 
    LinkedListQueue q2(q1);
    q1.addQueue(1000);
    q1.addQueue(2000);
    q1.printQueue();
    cout << endl;
 
    //q2.printQueue();
    cout << endl;
 
    q1.initializeQueue();
    q1.printQueue();
    cout << endl;
 
    q1.addQueue(35);
    cout << q1.front() << endl;
    cout << q1.front() << endl;
    q1.addQueue(3);
    q1.printQueue();
 
    return 0;
}
