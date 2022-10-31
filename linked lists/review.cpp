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

class List {
private:
	Node* head;
public:
	List() {
		head = NULL;
	}
	~List() {
		Node* currNode = head;
		Node* nextNode = NULL;
		while (currNode) {
			nextNode = currNode->next;
			delete currNode;
			currNode = nextNode;
		}
	}
	int findNode(int x) {
		Node* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data != x) {
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode)
			return currIndex;
		return -1;
	}
	Node* insertNode(int index, int x) {
		if (index < 0) {
			return NULL;
		}
		Node* currNode = head;
		int currIndex = 1;
		while (currNode && index > currIndex) {
			currNode = currNode->next;
			currIndex++;
		}
		if (!currNode && index > 0) {
			return NULL;
		}
		Node* newNode = new Node(x);
		if (index == 0) {
			newNode->next = head;
			head = newNode;
		}
		else {
			newNode->next = currNode->next;
			currNode->next = newNode;
		}
		return newNode;
	}
	void displayAll() {
		Node* currNode = head;
		while (currNode) {
			cout << currNode->data << " ";
			currNode = currNode->next;
		}
	}
	void recPrint(Node* curr) {
		if (curr) {
			recPrint(curr->next);
			cout << curr->data << endl;
		}
	}
	void insertAtFront(int x) {
		Node* newNode = new Node(x);
		if (!head) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}
	void deleteFirst() {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	void deleteLast() {
		Node* temp = head;
		Node* prev = NULL;
		while (temp->next != NULL) {
			prev = temp;
			temp = temp->next;
		}
		if (!prev) {
			head = head->next;
			delete temp;
		}
		else {
			prev->next = temp->next;
			delete temp;
		}
	}
	int middleNode() {
		Node* middle = head;
		Node* end = head;
		while (end != NULL && end->next != NULL) {
			middle = middle->next;
			end = end->next->next;
		}
		return middle->data;
	}
	void CopyList(List obj) {
		Node* first = obj.head;
		while (obj.head) {
			Node* newNode = new Node(obj.head->data);
			if (!head) {
				head = newNode;
				//last = newNode;
			}
			else {
				//last->next = newNode;
				//last = newNode;
			}
			obj.head = obj.head->next;
		}
		obj.head = first;
	}
	bool isInList(Node* ptr, int data) {
		while (ptr) {
			if (ptr->data == data) {
				return true;
			}
			ptr = ptr->next;
		}
		return false;
	}

	void insertAtLast(int x) {
		Node* newNode = new Node(x);
		if (!head) {
			head = newNode;
		}
		else {
			Node* curr = head;
			while (curr->next) {
				curr = curr->next;
			}
			curr->next = newNode;
		}
	}

	List unionList(List obj) {
		Node* curr1 = head, *curr2 = obj.head;
		List newList;
		while (curr1) {
			if (!isInList(newList.head, curr1->data)) {
				newList.insertAtLast(curr1->data);
			}
			curr1 = curr1->next;
		}
		while (curr2) {
			if (!isInList(newList.head, curr2->data)) {
				newList.insertAtLast(curr2->data);
			}
			curr2 = curr2->next;
		}
		return newList;
	}
	List intersectList(List obj) {
		Node* curr1 = head;
		Node* curr2 = obj.head;
		List newList;
		while (curr1) {
			if (isInList(newList.head, curr1->data) && !isInList(newList.head, curr1->data)) {
				newList.insertAtLast(curr1->data);
			}
			curr1 = curr1->next;
		}
		return newList;
	}

	int deleteNode(int x) {
		Node* prevNode = NULL;
		Node* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->data != x) {
			prevNode = currNode;
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode) {
			if (prevNode) {
				prevNode->next = currNode->next;
				delete currNode;
			}
			else {
				head = currNode->next;
				delete currNode;
			}
			return currIndex;
		}
		return 0;
	}

};

int main() {

	List obj;
	obj.insertNode(0, 24);
	obj.insertNode(1, 45);
	obj.insertNode(2, 36);
	obj.displayAll();
	cout << endl;
	cout << obj.findNode(36) << endl;
	obj.insertAtFront(13);
	obj.displayAll();
	cout << endl << obj.findNode(36) << endl;
	obj.deleteFirst();
	obj.insertAtFront(13);
	obj.displayAll();
	cout << endl << obj.middleNode() << endl;

	obj.insertAtLast(43);
	obj.displayAll();
	return 0;
}
