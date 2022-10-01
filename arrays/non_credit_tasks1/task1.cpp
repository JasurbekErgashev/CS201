#include <iostream>
using namespace std;

bool insertItem(int[], int, int);
int storedData{0};

int main() {

	int arr[5] = { 1, 2, 3, 4, 5 };
	cout << boolalpha <<insertItem(arr, 5, 4) << endl;
	cout << storedData;

	return 0;
}


bool insertItem(int arr[], int size, int index) {
	if (index < 0 || index >= size)
		return false;
	else {
		storedData = arr[index];
		return true;
	}
}
