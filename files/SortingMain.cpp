#include <iostream>
#include "MyArray.h"
#include "MyNumber.h"
using namespace std;

// Problem test set funcitons
void SSTest();

// function prototypes
string passEval(bool pass);

// Selection Sort test functions
bool testCase1SS();
bool testCase2SS();
bool testCase3SS();
bool testCase4SS();

int main(int argc, char **argv){

     // problem number passed in from php
     // based on current client problem
     int problem = stoi(argv[1]);

     // Select proper test set based on problem
     if(problem == 1) SSTest();

     return 0;
}

string passEval(bool pass){
     if(pass) return "Passed";
     return "Failed";
}

// Selection Sort test set
void SSTest(){
     
     // Test case 1
     bool pass1 = testCase1SS();
     cout << "Test 1: " << passEval(pass1) << endl;
     
     // Logic error hint
     if(!pass1) cout << "Double check how you are comparing array elements." << "\n\n";

     // Test case 2
     bool pass2 = testCase2SS();
     cout << "Test 2: " << passEval(pass2) << endl;

     // Logic error hint
     if(!pass2) cout << "Make sure that you are not sorting or comparing elements unnecessarily." << "\n\n";

     // Test case 3
     bool pass3 = testCase3SS();
     cout << "Test 3: " << passEval(pass3) << endl;

     // Logic error hint
     if(!pass3) cout << "Need to consider what the correct behaviour should be if there is no sorting needed." << "\n\n";

     // Test case 4
     bool pass4 = testCase4SS();
     cout << "Test 4: " << passEval(pass4) << endl;
     
     // Logic error hint
     if(!pass4) cout << "Need to consider how the function should behave in the worst case scenario for sorting an array." << "\n\n";
}

/////////////////////////////////////
// Start of Selection Sort Test Cases
/////////////////////////////////////

// For base case of array of n elements
bool testCase1SS(){
     bool correct = false;
     MyArray* systemArr = new MyArray(5);
     MyArray* userArr = new MyArray(5);

     systemArr->InitRandom(50);
     userArr->Copy(systemArr);
     userArr->Reset();
     systemArr->Reset();
      
     systemArr->SelectionSort(); 
     userArr->MySelectionSort();
     
     if(userArr->IsSorted() && userArr->TotalAssigns() == systemArr->TotalAssigns()
      && userArr->TotalComps() == systemArr->TotalComps()) correct = true;

     return correct;
}

// For edge case of 1 element
bool testCase2SS(){
     bool correct = false;
     MyArray* systemArr = new MyArray(1);
     MyArray* userArr = new MyArray(1);

     systemArr->InitRandom(50);
     userArr->Copy(systemArr);
     userArr->Reset();
     systemArr->Reset();

     systemArr->SelectionSort();
     userArr->MySelectionSort();

     if(userArr->IsSorted() && userArr->TotalAssigns() == systemArr->TotalAssigns()
      && userArr->TotalComps() == systemArr->TotalComps()) correct = true;
     return correct;
}

// For edge case of n elements pre-sorted ascending
bool testCase3SS(){
     bool correct = false;
     MyArray* systemArr = new MyArray(5);
     MyArray* userArr = new MyArray(5);

     systemArr->InitSortedAscending(50);
     userArr->Copy(systemArr);
     userArr->Reset();
     systemArr->Reset();

     systemArr->SelectionSort();
     userArr->MySelectionSort();

     if(userArr->IsSorted() && userArr->TotalAssigns() == systemArr->TotalAssigns()
      && userArr->TotalComps() == systemArr->TotalComps()) correct = true;
     return correct;
}

// For edge case of n elements pre-sorted descending
bool testCase4SS(){
     bool correct = false;
     MyArray* systemArr = new MyArray(5);
     MyArray* userArr = new MyArray(5);

     systemArr->InitSortedDescending(50);
     userArr->Copy(systemArr);
     userArr->Reset();
     systemArr->Reset();

     systemArr->SelectionSort();
     userArr->MySelectionSort();

     if(userArr->IsSorted() && userArr->TotalAssigns() == systemArr->TotalAssigns()
      && userArr->TotalComps() == systemArr->TotalComps()) correct = true;
     return correct;
}

///////////////////////////////////
// End of Selection Sort Test Cases
///////////////////////////////////