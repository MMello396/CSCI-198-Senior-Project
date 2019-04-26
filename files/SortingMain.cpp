#include <iostream>
#include <tuple>
#include "MyArray.h"
#include "MyNumber.h"
using namespace std;

// Problem test set funcitons
void SSTest();

// function prototypes
string passEval(bool pass);

// Selection Sort test functions
tuple<int, int, bool, bool> testCase1SS();
tuple<int, int, bool, bool> testCase2SS();
tuple<int, int, bool, bool> testCase3SS();
tuple<int, int, bool, bool> testCase4SS();

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
     // tuple<int, int, int, bool> pass1 = testCase1SS
     tuple<int, int, bool, bool> pass1 = testCase1SS();
     cout << "Test 1: " << passEval(get<3>(pass1)) << endl;
     cout << "Number of comparisons: " << get<0>(pass1) << "\nNumber of Assignments: " << get<1>(pass1) << endl;
     if (get<2>(pass1)) {
          cout << "The array is correctly sorted.\n\n";
     } else{
          cout << "The array is incorrectly sorted.\n\n";
     };

     // Logic error hint
     if (!get<3>(pass1))
          cout << "Double check how you are comparing array elements."
               << "\n\n";

     // Test case 2
     tuple<int, int, bool, bool> pass2 = testCase2SS();
     cout << "Test 2: " << passEval(get<3>(pass2)) << endl;
     cout << "Number of comparisons: " << get<0>(pass2) << "\nNumber of Assignments: " << get<1>(pass2) << endl;
     if (get<2>(pass2))
     {
          cout << "The array is correctly sorted.\n\n";
     }
     else
     {
          cout << "The array is incorrectly sorted.\n\n";
     };

     // Logic error hint
     if (!get<3>(pass2))
          cout << "Make sure that you are not sorting or comparing elements unnecessarily."
               << "\n\n";

     // Test case 3
     tuple<int, int, bool, bool> pass3 = testCase3SS();
     cout << "Test 3: " << passEval(get<3>(pass3)) << endl;
     cout << "Number of comparisons: " << get<0>(pass3) << "\nNumber of Assignments: " << get<1>(pass3) << endl;
     if (get<2>(pass3))
     {
          cout << "The array is correctly sorted.\n\n";
     }
     else
     {
          cout << "The array is incorrectly sorted.\n\n";
     };

     // Logic error hint
     if (!get<3>(pass3))
          cout << "Need to consider what the correct behaviour should be if there is no sorting needed."
               << "\n\n";

     // Test case 4
     tuple<int, int, bool, bool> pass4 = testCase4SS();
     cout << "Test 4: " << passEval(get<3>(pass4)) << endl;
     cout << "Number of comparisons: " << get<0>(pass4) << "\nNumber of Assignments: " << get<1>(pass4) << endl;
     if (get<2>(pass4))
     {
          cout << "The array is correctly sorted.\n\n";
     }
     else
     {
          cout << "The array is incorrectly sorted.\n\n";
     };

     // Logic error hint
     if (!get<3>(pass4))
          cout << "Need to consider how the function should behave in the worst case scenario for sorting an array."
               << "\n\n";
}

// /////////////////////////////////////
// // Start of Selection Sort Test Cases
// /////////////////////////////////////

// For base case of array of n elements
tuple<int, int, bool, bool> testCase1SS(){
     bool correct = false;
     MyArray* systemArr = new MyArray(5);
     MyArray* userArr = new MyArray(5);

     systemArr->InitRandom(50);
     userArr->Copy(systemArr);
     userArr->Reset();
     systemArr->Reset();
     
     systemArr->SelectionSort(); 
     userArr->MySelectionSort();     
     
     // Determines if the alorithm is working properly
     if (userArr->IsSorted() && userArr->TotalAssigns() == systemArr->TotalAssigns() && userArr->TotalComps() == systemArr->TotalComps()) correct = true;
     
     // Builds the tuple for returning information from the test
     return make_tuple(userArr->TotalComps(), userArr->TotalAssigns(), userArr->IsSorted(), correct);
}

// For edge case of 1 element
tuple<int, int, bool, bool> testCase2SS()
{
     bool correct = false;
     MyArray* systemArr = new MyArray(1);
     MyArray* userArr = new MyArray(1);

     systemArr->InitRandom(50);
     userArr->Copy(systemArr);
     userArr->Reset();
     systemArr->Reset();

     systemArr->SelectionSort();
     userArr->MySelectionSort();

     // Determines if the alorithm is working properly
     if(userArr->IsSorted() && userArr->TotalAssigns() == systemArr->TotalAssigns()
      && userArr->TotalComps() == systemArr->TotalComps()) correct = true;

     // Builds the tuple for returning information from the test
     return make_tuple(userArr->TotalComps(), userArr->TotalAssigns(), userArr->IsSorted(), correct);
}

// For edge case of n elements pre-sorted ascending
tuple<int, int, bool, bool> testCase3SS(){
     bool correct = false;
     MyArray* systemArr = new MyArray(10);
     MyArray* userArr = new MyArray(10);

     systemArr->InitSortedAscending(50);
     userArr->Copy(systemArr);
     userArr->Reset();
     systemArr->Reset();

     systemArr->SelectionSort();
     userArr->MySelectionSort();

     // Determines if the alorithm is working properly
     if(userArr->IsSorted() && userArr->TotalAssigns() == systemArr->TotalAssigns()
          && userArr->TotalComps() == systemArr->TotalComps()) correct = true;

     // Builds the tuple for returning information from the test
     return make_tuple(userArr->TotalComps(), userArr->TotalAssigns(), userArr->IsSorted(), correct);
}

// For edge case of n elements pre-sorted descending
tuple<int, int, bool, bool> testCase4SS(){
     bool correct = false;
     MyArray* systemArr = new MyArray(16);
     MyArray* userArr = new MyArray(16);

     systemArr->InitSortedDescending(50);
     userArr->Copy(systemArr);
     userArr->Reset();
     systemArr->Reset();

     systemArr->SelectionSort();
     userArr->MySelectionSort();

     // Determines if the alorithm is working properly
     if(userArr->IsSorted() && userArr->TotalAssigns() == systemArr->TotalAssigns()
          && userArr->TotalComps() == systemArr->TotalComps()) correct = true;

     // Builds the tuple for returning information from the test
     return make_tuple(userArr->TotalComps(), userArr->TotalAssigns(), userArr->IsSorted(), correct);
}

// ///////////////////////////////////
// // End of Selection Sort Test Cases
// ///////////////////////////////////