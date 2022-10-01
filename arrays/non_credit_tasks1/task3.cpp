#include <iostream>

using namespace std;

bool insertion(int[100], int, int);
bool deletion(int[100], int, int);
int linearSearch(int[], int, int);

int main() {

	cout << "Inserted 45: \n";
	int arr[100] = { 8, 22, 41, 0, 1, 51, 64, 8, 103 };
	cout << boolalpha << insertion(arr, 9, 45);

	cout << "\n\n";

	cout << "Deleted 5: \n";
	int arr1[100] = { 101, 23, 34, 41, 5, 63, 7, 80, 9, 11 };
	cout << boolalpha << deletion(arr1, 10, 5);

	cout << "\n\n";

	cout << "Linear Search: \n";
	int arr2[10] = { 15, 223, 33, 42, 5, 63, 7, 8, 91, 10 };
	cout << "Searching number is at index: " << linearSearch(arr2, 10, 8);

	cout << "\n\n";

	return 0;
}

bool insertion(int arr[100], int size, int item) {
	try {
		arr[size] = item;
		for (int i{ 0 }; i <= size; i++) {
			cout << arr[i] << ' ';
		}
		return true;
	}
	catch (exception e) {
		cout << "Something went wrong...";
		return false;
	}
}

bool deletion(int arr[100], int size, int item) {
	try {
		for (int i{ 0 }; i < size; i++) {
			if (item == arr[i]) {
				for (int j{ i }; j < size - 1; j++) {
					arr[j] = arr[j + 1];
				}
				arr[size - 1] = 0;
				break;
			}
		}
		for (int i{ 0 }; i < size - 1; i++) {
			cout << arr[i] << ' ';
		}
	}
	catch (exception e) {
		cout << "Something went wrong...\n";
		return false;
	}
}

int linearSearch(int arr[], int size, int num) {
	for (int i{ 0 }; i < size; i++) {
		if (num == arr[i]) {
			return i;
		}
	}
	return -1;
}
