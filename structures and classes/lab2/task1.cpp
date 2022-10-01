#include <iostream>

using namespace std;

struct empInfo {
	string name, email;
	int id;
	string designation;
	void input() {
		cout << "Enter name: "; cin >> name;
		cout << "Enter email: "; cin >> email;
		cout << "Enter id: "; cin >> id;
		cout << "Enter designation: "; cin >> designation;
	}
	void display() {
		cout << "Name: " << name;
		cout << "\nEmail: " << email;
		cout << "\nId: " << id;
		cout << "\nDesignation: " << designation << endl;
	}
};

int main() {
	empInfo emp;
	emp.input();
	system("cls");
	emp.display();
	return 0;
}
