#include <iostream>
#include <string>
#include <tuple>
#include "MyDCList.h"
using namespace std;

// Problem test set funcitons
void DCLITest();

// function prototypes
string passEval(bool pass);

// Doubly-Linked List Insertion test functions
tuple<bool,bool,bool> testCase1DCLI();
tuple<bool,bool,bool> testCase2DCLI();

int main(int argc, char **argv){

     // problem number passed in from php
     // based on current client problem
     int problem = stoi(argv[1]);

     // Select proper test set based on problem
     if(problem == 2) DCLITest();

     return 0;
}

string passEval(bool pass){
     if(pass) return "Passed";
     return "Failed";
}

// Doubly-Linked List Insertion test functions
void DCLITest(){

     // Test case 1
     tuple<bool,bool,bool> pass1 = testCase1DCLI();
     cout << "Test 1: " << passEval(get<2>(pass1)) << endl;
     if (get<0>(pass1)){
          cout << "Insertion of node: good.\n";
     } else {
          cout << "Insertion of node: bad.\n";
     }
     if (get<1>(pass1)){
          cout << "List link structure: good.\n\n";
     } else {
          cout << "List link structure: broken.\n\n";
     }     

     // Logic error hint
     if(!get<2>(pass1)) cout << "Make sure that the correct links are made for the newly inserted node." << "\n\n";

     // Test case 2
     tuple<bool,bool,bool> pass2 = testCase2DCLI();
     cout << "Test 2: " << passEval(get<2>(pass2)) << endl;
     if (get<0>(pass2)){
          cout << "Insertion of node: good.\n";
     } else {
          cout << "Insertion of node: bad.\n";
     }
     if (get<1>(pass2)){
          cout << "List link structure: good.\n\n";
     } else {
          cout << "List link structure: broken.\n\n";
     }

     // Logic error hint
     if(!get<2>(pass2)) cout << "How should the links be set if the newly added node is the only node?" << "\n\n";
}

///////////////////////////////////////////////////
// Start of Doubly-Linked List Insertion Test Cases
///////////////////////////////////////////////////

// test for standard case of a list of at least one element in the DLL 
tuple<bool,bool,bool> testCase1DCLI(){
     bool correct = false;
     MyDCList* systemList = new MyDCList();
     MyDCList* userList = new MyDCList();
     systemList->Insert(5);
     systemList->Insert(3);
     systemList->Insert(1);
     systemList->Insert(9);
     systemList->InsertHead(7);

     userList->Insert(5);
     userList->Insert(3);
     userList->Insert(1);
     userList->Insert(9);
     userList->MyInsertHead(7);

     // check for similarity in structure here
     if (userList->isSame(systemList) &&
     userList->structureGood()){
          correct = true;
     }   

     // Builds the tuple for returning information from the test
     return make_tuple(userList->isSame(systemList), userList->structureGood(), correct);
}

// test for edge case of insert when the list is of size zero.
tuple<bool,bool,bool> testCase2DCLI(){
     bool correct = false;
     MyDCList* systemList = new MyDCList();
     MyDCList* userList = new MyDCList();
     systemList->InsertHead(5);
     userList->MyInsertHead(5);

     // check for similarity in structure here
     if (userList->isSame(systemList) &&
     userList->structureGood()){
          correct = true;
     }   

     // Builds the tuple for returning information from the test
     return make_tuple(userList->isSame(systemList), userList->structureGood(), correct);
}

/////////////////////////////////////////////////
// End of Doubly-Linked List Insertion Test Cases
/////////////////////////////////////////////////