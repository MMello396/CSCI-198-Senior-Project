#include <iostream>
#include <string>
#include <tuple>
#include "MyDCList.h"
using namespace std;

// Problem test set funcitons
void DCLDTest();

// function prototypes
string passEval(bool pass);

// Doubly-Linked List Deletion test functions
tuple<bool, bool, bool> testCase1DCLD();
tuple<bool, bool, bool> testCase2DCLD();
tuple<bool, bool, bool> testCase3DCLD();

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
    tuple<bool, bool, bool> pass1 = testCase1DCLD();
    cout << "Test 1: " << passEval(get<2>(pass1)) << endl;
    if (get<0>(pass1)){
        cout << "Deletion of correct node: good.\n";
    } else {
        cout << "Deletion of correct node: bad.\n";
    }
    if (get<1>(pass1)){
        cout << "List link structure: good.\n\n";
    } else {
        cout << "List link structure: broken.\n\n";
    }
    

    // Logic error hint
    if (!get<2>(pass1))
        cout << "Be sure to make the necessary links between remaining nodes before deleting the node.\nThis will ensure access to portions of the list is not lost."
             << "\n\n";

    // Test case 2
    tuple<bool, bool, bool> pass2 = testCase2DCLD();
    cout << "Test 2: " << passEval(get<2>(pass2)) << endl;
    if (get<0>(pass2)){
        cout << "Deletion of correct node: good.\n";
    } else {
        cout << "Deletion of correct node: bad.\n";
    }
    if (get<1>(pass2)){
        cout << "List link structure: good.\n\n";
    } else {
        cout << "List link structure: broken.\n\n";
    }

    // Logic error hint
    if(!get<2>(pass2)) cout << "Make sure your code handles cases where there are no nodes in the list." << "\n\n";

    // Test case 3
    tuple<bool, bool, bool> pass3 = testCase3DCLD();
    cout << "Test 3: " << passEval(get<2>(pass3)) << endl;
    if (get<0>(pass3)){
        cout << "Deletion of correct node: good.\n";
    } else {
        cout << "Deletion of correct node: bad.\n";
    }
    if (get<1>(pass3)){
        cout << "List link structure: good.\n\n";
    } else {
        cout << "List link structure: broken.\n\n";
    }

    // Logic error hint
    if(!get<2>(pass3)) cout << "Make sure your code handles cases where there are no nodes left in the list after deleting the node." << "\n\n";
}

//////////////////////////////////////////////////
// Start of Doubly-Linked List Deletion Test Cases
//////////////////////////////////////////////////

// Default case where there are n nodes in the list and the front is to be deleted.
tuple<bool, bool, bool> testCase1DCLD()
{
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
        if (userList->isSame(systemList) &&
        userList->structureGood()){
            correct = true;
        }   
    }

    // Builds the tuple for returning information from the test
    return make_tuple(userList->isSame(systemList), userList->structureGood(), correct);
}

// Edge case where there are no nodes in the list before attempting to delete the head node.
tuple<bool, bool, bool> testCase2DCLD(){
    bool correct = false;

    MyDCList* systemList = new MyDCList();
    MyDCList* userList = new MyDCList();
    systemList->DeleteHead();
    userList->MyDeleteHead();

    // check for similarity in structure here
    if (userList->isSame(systemList) &&
    userList->structureGood()){
        correct = true;
    }   

    // Builds the tuple for returning information from the test
    return make_tuple(userList->isSame(systemList), userList->structureGood(), correct);
}

// Edge case where there are no nodes left in the list after deleting the head node.
tuple<bool, bool, bool> testCase3DCLD(){
    bool correct = false;

    MyDCList* systemList = new MyDCList();
    MyDCList* userList = new MyDCList();
    systemList->Insert(4);
    userList->Insert(4);
    systemList->DeleteHead();
    userList->MyDeleteHead();

    // check for similarity in structure here
    if (userList->isSame(systemList) &&
    userList->structureGood()){
        correct = true;
    }   

    // Builds the tuple for returning information from the test
    return make_tuple(userList->isSame(systemList), userList->structureGood(), correct);
}

////////////////////////////////////////////////
// End of Doubly-Linked List Deletion Test Cases
////////////////////////////////////////////////