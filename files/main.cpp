#include "MyArray.h"
#include "MyNumber.h"
#include "MyDCList.h"
#include <iostream>
using namespace std;

// Problem test set funcitons
void SSTest();
void DLLITest();
void DLLDTest();

// function prototypes
string passEval(bool pass);

// Selection Sort test functions
bool testCase1SS();
bool testCase2SS();
bool testCase3SS();
bool testCase4SS();

// Doubly-Linked List Insertion test functions
bool testCase1DLLI();
bool testCase2DLLI();
bool testCase3DLLI();
bool testCase4DLLI();
bool testCase5DLLI();

// Doubly-Linked List Deletion test functions
bool testCase1DLLD();
bool testCase2DLLD();
bool testCase3DLLD();
bool testCase4DLLD();
bool testCase5DLLD();

int main(int argc, char **argv){

     // problem number passed in from php
     // based on current client problem
     int problem = stoi(argv[1]);

     // Select proper test set based on problem
     if(problem == 1) SSTest();
     if(problem == 2) DLLITest();
     if(problem == 3) DLLDTest();

     return 0;
}

string passEval(bool pass){
     if(pass) return "Passed";
     return "Failed";
}

// Selection Sort test set
void SSTest(){
     bool pass1 = testCase1SS();
     cout << "Test 1: " << passEval(pass1) << endl;
     
     // Write an logic error hint here for each test case

     bool pass2 = testCase2SS();
     cout << "Test 2: " << passEval(pass2) << endl;

     bool pass3 = testCase3SS();
     cout << "Test 3: " << passEval(pass3) << endl;

     bool pass4 = testCase4SS();
     cout << "Test 4: " << passEval(pass4) << endl;
}

// Doubly-Linked List Insertion test functions
void DLLITest(){
     bool pass1 = testCase1DLLI();
     cout << "Test 1: " << passEval(pass1) << endl;
     
     bool pass2 = testCase2DLLI();
     cout << "Test 2: " << passEval(pass2) << endl;

     bool pass3 = testCase3DLLI();
     cout << "Test 3: " << passEval(pass3) << endl;
}

// Doubly-Linked List Deletion test functions
void DLLDTest(){
     bool pass1 = testCase1DLLD();
     cout << "Test 1: " << passEval(pass1) << endl;
     
     bool pass2 = testCase2DLLD();
     cout << "Test 2: " << passEval(pass2) << endl;

     bool pass3 = testCase3DLLD();
     cout << "Test 3: " << passEval(pass3) << endl;
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
     // for some reason the operator is just assigning the pointers rather than using the overloaded function i defined in MyArray.h
     // userArr = systemArr;
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

///////////////////////////////////////////////////
// Start of Doubly-Linked List Insertion Test Cases
///////////////////////////////////////////////////

// test for standard case of a list of at least one element in the DLL 
bool testCase1DLLI(){
     bool correct = false;
     MyDCList* sysList = new MyDCList();
     sysList->InsertHead(5);
     MyDCList* userList = new MyDCList();
     sysList->MyInsertHead(5);

     // check for similarity in structure here

     return correct;
}

// test for edge case of insert when the list is of size zero.
bool testCase2DLLI(){
     bool correct = false;

     return correct;
}

/////////////////////////////////////////////////
// End of Doubly-Linked List Insertion Test Cases
/////////////////////////////////////////////////

//////////////////////////////////////////////////
// Start of Doubly-Linked List Deletion Test Cases
//////////////////////////////////////////////////

// 
bool testCase1DLLD(){
     bool correct = false;

     return correct;
}

// 
bool testCase2DLLD(){
     bool correct = false;

     return correct;
}

// 
bool testCase3DLLD(){
     bool correct = false;

     return correct;
}

////////////////////////////////////////////////
// End of Doubly-Linked List Deletion Test Cases
////////////////////////////////////////////////