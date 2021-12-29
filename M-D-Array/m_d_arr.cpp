//
// Created by puff on 12/25/21.
//
#include <iostream>

using namespace std;

int main() {
  int rows = 5;

  // allocate and initialize the array
  int **arr = new int *[rows];
  for (int r = 0; r < rows; r++) {
    arr[r] = new int[r + 1];
    for (int c = 0; c <= r; c++)
      arr[r][c] = (r + 1) * 10 + c + 1;
  }

  // print the array
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c <= r; c++)
      cout << arr[r][c] << " ";
    cout << endl;
  }

  // free the array
  for (int r = 0; r < rows; r++)
    delete[] arr[r];
  delete[] arr;

}

