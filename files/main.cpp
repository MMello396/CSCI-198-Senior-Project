#include "MyArray.h"
#include "MyNumber.h"
#include <iostream>
using namespace std;

int main(){

     bool sorted = false;
     MyArray* arr = new MyArray(5);
     cout << "Array Size: " << arr->GetSize() << endl;

     arr->InitRandom(50);
     arr->Reset();
     arr->Display();
     
     // arr->SelectionSort();
     arr->MySelectionSort();
     arr->Display();
     
     // Display number of comparisons and assigns
     arr->DisplayStats();
     
     sorted = arr->IsSorted();
     cout << "\nArray is Sorted: " << sorted << endl
         << endl;


     return 0;
}void MyArray::MySelectionSort(){
     cout << "\nIm a function defined by the user! Wohoo, I'm being ran!" << endl;
     for (int i = 0; i < n; ++i) {
		int min = i; // min = index of the minimum value for the array between 
		for (int j = i + 1; j < n; ++j) { // search for the minimum index j between i and n-1
			if (a[j] < a[min]) {
				min = j;
			}
		}
		SwapIndex(i, min);
	}
}