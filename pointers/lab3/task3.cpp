#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class TwoDRandArray {
private:
  int **Ptr;
  int numRows;
  int *numColsPtr;

public:
  TwoDRandArray(int numRows, int numColsFun[]) {
    this->numRows = numRows;
    Ptr = new int *[numRows];
    for (int i{0}; i < numRows; i++) {
      Ptr[i] = new int[numColsFun[i]];
      for (int j{0}; j < numColsFun[i]; j++) {
        Ptr[i][j] = 0;
      }
    }
  };
  void output() {
    for (int i{0}; i < numRows; i++) {
      for (int j{0}; j < *(numColsPtr + i); j++) {
        cout << Ptr[i][j];
      }
    }
  };
  void getInput() {
    for (int i{0}; i < numRows; i++) {
      for (int j{0}; j < *(numColsPtr + i); j++) {
        cin >> Ptr[i][j];
      }
    }
  };
  ~TwoDRandArray() {
    delete[] numColsPtr;
    delete[] Ptr;
  };
};

int main() {
  // this code does not work
  // there is a serious bug
  // leaving as it is for future reference
  int arr[3] = {1, 2, 3};
  TwoDRandArray obj(3, arr);
  obj.output();
};
