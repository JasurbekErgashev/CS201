#include <iostream>
#include <vector>

using namespace std;

class Complex {
public:
	Complex() {
		L = 0;
		I = 0;
	}
	Complex(const double& L, const double& I) {
		this->L = L;
		this->I = I;
	}
	vector<double> add(const double& L2, const double& I2) {
		return {L + L2, I + I2};
	}

	vector<double> subtract(const double& L2, const double& I2) {
		return {L - L2, I - I2};
	}

	void print(const vector<double>& complexNum) {
		cout << "(" << complexNum[0] << ", " << complexNum[1] << ")" << endl;
	}

private:
	double L;
	double I;
};

int main() {

	Complex obj1(2, 3);

	cout << "Addition: ";
	obj1.print(obj1.add(5, 6));

	cout << "Subtraction: ";
	obj1.print(obj1.subtract(5, 6));

	return 0;
}
