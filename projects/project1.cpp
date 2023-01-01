#include <iostream>
 
using namespace std;
 
class Child {
private:
    int age;
    string name;
public:
    Child(int age, string name) {
        setAge(age);
        setName(name);
        nextChild = NULL;
    }
    Child* nextChild;
    int getAge() {
        return age;
    };
    void setAge(int age) {
        this->age = age;
    };
    string getName() {
        return name;
    };
    void setName(string name) {
        this->name = name;
    };
};
 
class Spouse {
private:
    int age;
    string name;
    int num_children;
    Child* childHead;
    void insertChildAtFront(int age, string name) {
        Child* newChild = new Child(age, name);
        if (childHead == NULL)
            childHead = newChild;
        else {
            newChild->nextChild = childHead;
            childHead = newChild;
        }
    };
public:
    Spouse(int age, string name) {
        setAge(age);
        setName(name);
        cout << "Enter the number of children: ";
        cin >> num_children;
        childHead = NULL;
        if (num_children <= 0)
            num_children = 0;
        else
            childrenDetails();
    }
    int getAge() {
        return age;
    };
    void setAge(int age) {
        this->age = age;
    };
    string getName() {
        return name;
    };
    void setName(string name) {
        this->name = name;
    };
    void childrenDetails() {
        for (int i = 1; i <= num_children; i++) {
            cout << "Enter the name of the child " << i << ": ";
            string childName; cin >> childName;
            cout << "Enter the age of the child " << i << ": ";
            int childAge; cin >> childAge;
            insertChildAtFront(age, name);
        }
    };
    void printChildrenDetails() {
        Child* currChild = childHead;
        while (currChild != NULL) {
            cout << "name: " << currChild->getName() << "   age: " << currChild->getAge() << endl;
            currChild->nextChild;
        }
    };
    ~Spouse() {
        Child* currChild = childHead;
        while (currChild != NULL) {
            childHead = currChild->nextChild;
            delete currChild;
            currChild = childHead;
        }
    }
};
 
struct Employee {
    bool isSpouseAvailable;
    string employee_name, designation, email;
    int employee_id, age;
    Employee* nextEmployee;
 
    Employee(string employee_name, string designation, string email, int employee_id, int age) {
        this->employee_name = employee_name;
        this->designation = designation;
        this->email = email;
        this->employee_id = employee_id;
        this->age = age;
        cout << "Enter 1 if employee is married, 0 otherwise: ";
        cin >> isSpouseAvailable;
        nextEmployee = NULL;
        if (isSpouseAvailable)
            spouseDetails();
        else
            spouseLink = NULL;
    }
 
    void printChildrenDetails() {
        spouseLink->printChildrenDetails();
    }
 
    ~Employee() {
        delete spouseLink;
    }
 
private:
    Spouse* spouseLink;
    void spouseDetails() {
        cout << "Enter the name of the spouse: ";
        string spouseName; cin >> spouseName;
        cout << "Enter the age of the spouse: ";
        int spouseAge; cin >> spouseAge;
        spouseLink = new Spouse(spouseAge, spouseName);
    };
};
 
struct List {
    List() {
        head = NULL;
    }
    void insertEmployeeAtFront(string employee_name, string designation, string email, int employee_id, int age) {
        Employee* newEmployee = new Employee(employee_name, designation, email, employee_id, age);
        if (!head) {
            head = newEmployee;
        }
        else {
            newEmployee->nextEmployee = head;
            head = newEmployee;
        }
    };
    void printAllEmpChildDetails() {
        Employee* curr = head;
        while (curr != NULL) {
            curr->printChildrenDetails();
            curr->nextEmployee;
        }
    };
private:
    Employee* head;
};
 
int main(){
    List list1;
    list1.insertEmployeeAtFront("xyzzzzz3", "prof", "xssds3@gmail.com", 23333, 34);
    list1.insertEmployeeAtFront("xyzzzzz2", "prof", "xssds2@gmail.com", 23332, 33);
    list1.insertEmployeeAtFront("xyzzzzz1", "prof", "xssds1@gmail.com", 23331, 32);
 
    list1.printAllEmpChildDetails();
   
    return 0;
}
