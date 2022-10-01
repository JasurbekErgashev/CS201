#include <iostream>
using namespace std;

class EmpInfo {
public:
	EmpInfo(const string& n, const string& e, const int& i, const string& d) {
		set_name(n);
		set_email(e);
		set_id(i);
		set_designation(d);
	}

	void set_name(const string& name) {
		this->name = name;
	}
	string get_name() const {
		return name;
	}

	void set_email(const string& email) {
		this->email = email;
	}
	string get_email() const {
		return email;
	}

	void set_id(const int& id) {
		this->id = id;
	}
	int get_id() const {
		return id;
	}

	void set_designation(const string& designation) {
		this->designation = designation;
	}
	string get_designation() const {
		return designation;
	}

	void input() {
		cout << "Name: "; cin >> name;
		cout << "Email: "; cin >> email;
		cout << "ID: "; cin >> id;
		cout << "Designation: "; cin >> designation;
		system("cls");
	}

	void output() {
		cout << "Name: " << name << endl;
		cout << "Email: " << email << endl;
		cout << "ID: " << id << endl;
		cout << "Designation: " << designation << endl;
	}

private:
	string name, email;
	int id;
	string designation;
};

int main() {

	EmpInfo empInfoObj("Jasurbek", "ac2303018@akfauniversity.org", 210071, "Computer Science");
	empInfoObj.output();

	cout << endl;
	empInfoObj.input();

	empInfoObj.output();

	return 0;
}
