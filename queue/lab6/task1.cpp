#include <iostream>
 
using namespace std;
 
class Queue{
public:
     Queue() {
        maxQueueSize = 100;
        count = 0;
        queueFront = 0;
        queueRear = maxQueueSize - 1;
        list = new int[maxQueueSize];
    };
    Queue(int queueSize) {
        if (queueSize <= 0)
            maxQueueSize = 100;
        else
            maxQueueSize = queueSize;
        count = 0;
        queueFront = 0;
        queueRear = maxQueueSize - 1;
        list = new int[maxQueueSize];
    }
    bool isEmptyQueue() {
        return count == 0;
    }
    bool isFullQueue() {
        return count == maxQueueSize;
    }
    void initializeQueue() {
        queueFront = 0;
        queueRear = maxQueueSize - 1;
        count = 0;
    }
    int front() {
        if (!isEmptyQueue())
            return list[queueFront];
        throw "Queue is empty";
    }
    int back() {
        if (!isEmptyQueue())
            return list[queueRear];
        throw "Queue is empty";
    }
    void addQueue(const int& queueElement) {
        if (!isFullQueue()) {
            queueRear = (queueRear + 1) % maxQueueSize;
            count++;
            list[queueRear] = queueElement;
        }
        else
            cout << "Queue is already full" << endl;
    };
    void deleteQueue() {
        if (!isEmptyQueue()) {
            count--;
            queueFront = (queueFront + 1) % maxQueueSize;
        }
        else {
            cout << "Queue is empty" << endl;
        }
    };
 
    void printQueue() {
        if (!isEmptyQueue()) {
            if (queueRear >= queueFront) {
                for (int i = queueFront; i <= queueRear; i++) {
                    cout << list[i] << " ";
                }
            }
            else {
                for (int i = queueFront; i < maxQueueSize; i++) {
                    cout << list[i] << " ";
                }
                for (int i = 0; i < queueRear; i++) {
                    cout << list[i] << " ";
                }
            }
        }
        else {
            cout << "An empty Queue can't be displayed";
        }
    }
   
    Queue(const Queue& otherQueue) {
        maxQueueSize = otherQueue.maxQueueSize;
        count = otherQueue.count;
        queueFront = otherQueue.queueFront;
        queueRear = otherQueue.queueRear;
        list = new int[maxQueueSize];
        if (!isEmptyQueue()) {
            if (queueRear >= queueFront) {
                for (int i = queueFront; i <= queueRear; i++) {
                    list[i] = otherQueue.list[i];
                }
            }
            else {
                for (int i = queueFront; i < maxQueueSize; i++) {
                    list[i] = otherQueue.list[i];
                }
                for (int i = 0; i < queueRear; i++) {
                    list[i] = otherQueue.list[i];
                }
            }
        }
        else
            cout << "Queue is empty";
    };
 
    ~Queue() {
        delete[] list;
    };
private:
    int maxQueueSize;
    int count;
    int queueFront;
    int queueRear;
    int *list;
};
int main(){
   
    Queue q1;
 
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
 
    Queue q2(q1);
 
    q1.addQueue(1000);
    q1.addQueue(2000);
    q1.printQueue();
    cout << endl;
 
    q2.printQueue();
    cout << endl;
 
    q1.initializeQueue();
    q1.printQueue();
    cout << endl;
 
    q1.addQueue(35);
    cout << q1.front() << endl;
 
    cout << q1.front() << endl;
 
    q1.addQueue(3);
    q1.printQueue();
    cout << endl;
 
 
    return 0;
}
