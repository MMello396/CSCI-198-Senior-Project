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
bool testCase1DCLI();
bool testCase2DCLI();

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
     bool pass1 = testCase1DCLI();
     cout << "Test 1: " << passEval(pass1) << endl;
     
     // Logic error hint
     if(!pass1) cout << "Make sure that the correct links are made for the newly inserted node." << "\n\n";

     // Test case 2
     bool pass2 = testCase2DCLI();
     cout << "Test 2: " << passEval(pass2) << endl;

     // Logic error hint
     if(!pass2) cout << "How should the links be set if the newly added node is the only node?" << "\n\n";
}

///////////////////////////////////////////////////
// Start of Doubly-Linked List Insertion Test Cases
///////////////////////////////////////////////////

// test for standard case of a list of at least one element in the DLL 
bool testCase1DCLI(){
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
     if (userList->GetHead() != NULL && userList->GetTail() != NULL){
          if (systemList->GetHead()->data == userList->GetHead()->data &&
           systemList->GetTail()->data == userList->GetTail()->data &&
           userList->GetHead()->previous == NULL){
               correct = true;
          }   
     }
     
     return correct;
}

// test for edge case of insert when the list is of size zero.
bool testCase2DCLI(){
     bool correct = false;
     MyDCList* systemList = new MyDCList();
     MyDCList* userList = new MyDCList();
     systemList->InsertHead(5);
     userList->MyInsertHead(5);

     // check for similarity in structure here
     if (userList->GetHead() != NULL && userList->GetTail() != NULL){
          if (systemList->GetHead()->data == userList->GetHead()->data &&
           systemList->GetTail()->data == userList->GetTail()->data &&
           userList->GetHead()->previous == NULL){

               correct = true;
          }   
     }

     return correct;
}

/////////////////////////////////////////////////
// End of Doubly-Linked List Insertion Test Cases
/////////////////////////////////////////////////