#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int integers[10] = {};
    int result[10] = {};
    // input
    cout << "Input: ";
    for (int i{ 0 }; i < 10; i++) {
        int input;
        cin >> input;
        integers[i] = input;
    }
    // sorting
    sort(integers, integers + 10);
    // arranging values
    int start{ 0 };
    int end{ 9 };
    int tracker{ 0 };

    while (tracker < 10) {
        if (integers[tracker] % 2 == 0) {
            result[start] = integers[tracker];
            start++;
        }
        else {
            result[end] = integers[tracker];
            end--;
        }
        tracker++;
    }
    // output
    cout << "Output: ";
    for (int i{ 0 }; i < 10; i++) {
        cout << result[i] << ' ';
    }
}
