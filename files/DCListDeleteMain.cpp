#include <iostream>
#include <string>
#include "MyDCList.h"
using namespace std;

// Problem test set funcitons
void DCLDTest();

// function prototypes
string passEval(bool pass);

// Doubly-Linked List Deletion test functions
bool testCase1DCLD();
bool testCase2DCLD();
bool testCase3DCLD();

int main(int argc, char **argv){

    // problem number passed in from php
    // based on current client problem
    int problem = stoi(argv[1]);

    // Select proper test set based on problem
    if(problem == 3) DCLDTest();

    return 0;
}

string passEval(bool pass){
    if(pass) return "Passed";
    return "Failed";
}

// Doubly-Linked List Deletion test functions
void DCLDTest(){

    // Test case 1
    bool pass1 = testCase1DCLD();
    cout << "Test 1: " << passEval(pass1) << endl;
    
    // Logic error hint
    if(!pass1) cout << "Be sure to make the necessary links between remaining nodes before deleting the node.\nThis will ensure access to portions of the list is not lost." << "\n\n";

    // Test case 2
    bool pass2 = testCase2DCLD();
    cout << "Test 2: " << passEval(pass2) << endl;

    // Logic error hint
    if(!pass2) cout << "Make sure your code handles cases where there are no nodes in the list." << "\n\n";

    // Test case 3
    bool pass3 = testCase3DCLD();
    cout << "Test 3: " << passEval(pass3) << endl;

    // Logic error hint
    if(!pass3) cout << "Make sure your code handles cases where there are no nodes left in the list after deleting the node." << "\n\n";
}

//////////////////////////////////////////////////
// Start of Doubly-Linked List Deletion Test Cases
//////////////////////////////////////////////////

// Default case where there are n nodes in the list and the front is to be deleted. 
bool testCase1DCLD(){
    bool correct = false;
    
    MyDCList* systemList = new MyDCList();
    MyDCList* userList = new MyDCList();
    systemList->Insert(5);
    systemList->Insert(3);
    systemList->Insert(1);
    systemList->Insert(9);
    systemList->DeleteHead();

    userList->Insert(5);
    userList->Insert(3);
    userList->Insert(1);
    userList->Insert(9);
    userList->MyDeleteHead();

    // check for similarity in structure here
    if (userList->GetHead() != NULL){
        if (systemList->GetHead()->data == userList->GetHead()->data &&
        userList->GetHead()->previous == NULL){

            correct = true;
        }   
    }

    return correct;
}

// Edge case where there are no nodes in the list before attempting to delete the head node.
bool testCase2DCLD(){
    bool correct = false;

    MyDCList* systemList = new MyDCList();
    MyDCList* userList = new MyDCList();
    systemList->DeleteHead();
    userList->MyDeleteHead();

    // check for similarity in structure here
    if (systemList->GetHead() == userList->GetHead() && systemList->GetTail() == userList->GetTail()){
        correct = true;
    }   

    return correct;
}

// Edge case where there are no nodes left in the list after deleting the head node.
bool testCase3DCLD(){
    bool correct = false;

    MyDCList* systemList = new MyDCList();
    MyDCList* userList = new MyDCList();
    systemList->Insert(4);
    userList->Insert(4);
    systemList->DeleteHead();
    userList->MyDeleteHead();

    // check for similarity in structure here
    if (systemList->GetHead() == userList->GetHead() && systemList->GetTail() == userList->GetTail()){
        correct = true;
    }   

    return correct;
}

////////////////////////////////////////////////
// End of Doubly-Linked List Deletion Test Cases
////////////////////////////////////////////////