#include "MyArray.h"
#include "MyNumber.h"
#include <iostream>
using namespace std;

string passEval(bool pass);
bool testCase1SS();
bool testCase2SS();
bool testCase3SS();
bool testCase4SS();
bool testCase5SS();

int main(){


     bool pass1 = testCase1SS();
     cout << "Test 1: " << passEval(pass1) << endl;
     
     bool pass2 = testCase2SS();
     cout << "Test 2: " << passEval(pass2) << endl;

     bool pass3 = testCase3SS();
     cout << "Test 3: " << passEval(pass3) << endl;

     bool pass4 = testCase4SS();
     cout << "Test 4: " << passEval(pass4) << endl;

     bool pass5 = testCase5SS();
     cout << "Test 5: " << passEval(pass5) << endl;

     return 0;
}

string passEval(bool pass){
     if(pass) return "Passed";
     return "Failed";
}

// For base case of array of n elements
bool testCase1SS(){
     bool sorted = false;
     MyArray* systemArr = new MyArray(5);
     MyArray* userArr = new MyArray(5);
     // cout << "Array Size: " << systemArr->GetSize() << endl;

     systemArr->InitRandom(50);
     userArr = systemArr;
     // systemArr->Display();
     // userArr->Display();
     
     systemArr->SelectionSort();
     userArr->MySelectionSort();

     // systemArr->Display();
     // userArr->Display();
     if(userArr == systemArr) sorted = true;
     return sorted;
}

// For edge case of 1 element
bool testCase2SS(){
     bool sorted = false;
     MyArray* systemArr = new MyArray(1);
     MyArray* userArr = new MyArray(1);
     // cout << "Array Size: " << systemArr->GetSize() << endl;

     systemArr->InitRandom(50);
     userArr = systemArr;
     // systemArr->Display();
     // userArr->Display();
     
     systemArr->SelectionSort();
     userArr->MySelectionSort();

     // systemArr->Display();
     // userArr->Display();
     if(userArr == systemArr) sorted = true;
     return sorted;
}

// For edge case of 0 elements
bool testCase3SS(){
     bool sorted = false;
     MyArray* systemArr = new MyArray(0);
     MyArray* userArr = new MyArray(0);
     // cout << "Array Size: " << systemArr->GetSize() << endl;

     systemArr->InitRandom(50);
     userArr = systemArr;
     // systemArr->Display();
     // userArr->Display();
     
     systemArr->SelectionSort();
     userArr->MySelectionSort();

     // systemArr->Display();
     // userArr->Display();
     if(userArr == systemArr) sorted = true;
     return sorted;
}

// For edge case of n elements pre-sorted ascending
bool testCase4SS(){
     bool sorted = false;
     MyArray* systemArr = new MyArray(5);
     MyArray* userArr = new MyArray(5);
     // cout << "Array Size: " << systemArr->GetSize() << endl;

     systemArr->InitSortedAscending(50);
     userArr = systemArr;
     // systemArr->Display();
     // userArr->Display();
     
     systemArr->SelectionSort();
     userArr->MySelectionSort();

     // systemArr->Display();
     // userArr->Display();
     if(userArr == systemArr) sorted = true;
     return sorted;
}

// For case of n elements pre-sorted descending
bool testCase5SS(){
     bool sorted = false;
     MyArray* systemArr = new MyArray(5);
     MyArray* userArr = new MyArray(5);
     // cout << "Array Size: " << systemArr->GetSize() << endl;

     systemArr->InitSortedDescending(50);
     userArr = systemArr;
     // systemArr->Display();
     // userArr->Display();
     
     systemArr->SelectionSort();
     userArr->MySelectionSort();

     // systemArr->Display();
     // userArr->Display();
     if(userArr == systemArr) sorted = true;
     return sorted;
}