#include <iostream>
#include <algorithm>
using namespace std;

void noDup(int[4][5], int[20]);

int main() {
    int twoD[4][5] = {};
    for (int i{ 0 }; i < 4; i++) {
        for (int j{ 0 }; j < 5; j++) {
            cin >> twoD[i][j];
        }
    }
    int oneD[20] = {};
    noDup(twoD, oneD);
    return 0;
}

void noDup(int twoD[4][5], int oneD[20]) {
    int tempArr[20] = {};
    for (int i{ 0 }; i < 4; i++) {
        for (int j{ 0 }; j < 5; j++) {
            tempArr[5 * i + j] = twoD[i][j];
        }
    }
    sort(tempArr, tempArr + 20);
    oneD[0] = tempArr[0];
    int tracker{ 1 };
    for (int i{ 1 }; i < 20; i++) {
        if (tempArr[i] != tempArr[i - 1]) {
            oneD[tracker] = tempArr[i];
            tracker++;
        }
    }
    cout << "2D array: \n";
    for (int i{ 0 }; i < 4; i++) {
        for (int j{ 0 }; j < 5; j++) {
            cout << twoD[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "\n1D array: \n";
    for (int i{ 0 }; i < tracker; i++) {
        cout << oneD[i] << ' ';
    }


}
