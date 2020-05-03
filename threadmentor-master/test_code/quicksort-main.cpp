#include <iostream>
#include "quicksort.h"

int main(int argc, char *argv[]) {

    QuickSortThread *quicksortthread;
    int *array;
    int arraySize, i;
    cout << "Please input the array elements: " << endl;
    cin >> arraySize;
    array = new int[arraySize];

    cout << "Please input the array elements: " << endl;
    for (i = 0; i < arraySize; i++)
      cin >> array[i];

    cout << "Before quicksort, the array is:" << endl;
    for (i = 0; i < arraySize; i++)
      cout << array[i] << "   ";
    cout << endl;

    quicksortthread = new QuickSortThread(0, arraySize - 1, array);
    quicksortthread->Begin();
    quicksortthread->Join();
    cout << "After quicksort, the array is:" << endl;
    for (i = 0; i < arraySize; i++)
      cout << array[i] << "   ";
    cout << endl;
    Exit();
    return 0;
    

    
  } 
