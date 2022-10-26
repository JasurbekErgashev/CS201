#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main() {
    // dynamic memory allocation
    int size = 3;
    int track = 0;
    int* arrPtr = new int[size];
    int num;
    char check;
    while (true) {
        cout << "Enter a number: ";
        cin >> num;
        *(arrPtr + track) = num;
        track++;
        if (track >= size) {
            int* ptrTemp = new int[2 * size];
            for (int i{ 0 }; i < size; i++) {
                *(ptrTemp + i) = *(arrPtr + i);
            }
            delete[] arrPtr;
            arrPtr = ptrTemp;
            size *= 2;
        }
        cout << "Press y to enter another number: ";
        cin >> check;
        if (check != 'y')
            break;
    }
    for (int i{ 0 }; i < track; i++) {
        cout << *(arrPtr + i) << " ";
    }
    return 0;
}
