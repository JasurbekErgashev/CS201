#include <iostream>

using namespace std;

bool insertion(int[100], int, int);
bool deletion(int[100], int, int);
int linearSearch(int[], int, int);
int binarySearch(int[], int, int);
void iterations();

int linearIterations{ 0 };
int binaryIterations{ 0 };

int main() {

	cout << "Inserted 9: \n";
	int arr[100] = { 1, 2, 3, 4, 4, 5, 6, 8, 10 };
	cout << boolalpha << insertion(arr, 9, 9);

	cout << "\n\n";
	
	cout << "Deleted 5: \n";
	int arr1[100] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << boolalpha << deletion(arr1, 10, 5);

	cout << "\n\n";

	cout << "Linear Search: \n";
	int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << "Searching number is at index: " << linearSearch(arr2, 10, 8);

	cout << "\n\n";

	cout << "Binary Search: \n";
	int arr3[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "Searching number is at index: " << binarySearch(arr3, 10, 8);

	cout << "\n\n";

	iterations();

	cout << "\n\n";

	return 0;
}

bool insertion(int arr[100], int size, int item) {
	try {
		bool isLast = false;
		for (int i{ 0 }; i < size; i++) {
			if (item <= arr[i]) {
				for (int j{ size }; j > i; j--) {
					arr[j] = arr[j - 1];
				}
				arr[i] = item;
				isLast = true;
				break;
			}
		}
		if (!isLast)
			arr[size] = item;

		for (int i{ 0 }; i <= size; i++) {
			cout << arr[i] << ' ';
		}
		return true;
	}
	catch (exception e) {
		cout << "Something went wrong...\n";
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
		linearIterations++;
		if (num == arr[i]) {
			return i;
		}
	}
	return -1;
}

int binarySearch(int arr[], int size, int num) {
	int lower = 0;
	int upper = size - 1;
	int middle{0};
	while (true) {
		binaryIterations++;
		middle = (lower + upper) / 2;
		if (arr[middle] == num)
			return middle;
		else if(lower > upper)
			return -1;
		else {
			if (arr[middle] < num)
				lower = middle + 1;
			else
				upper = middle - 1;
		}
	}
}

void iterations() {
	cout << "Linear iterations: " << linearIterations << endl;
	cout << "Binary iterations: " << binaryIterations << endl;
}
