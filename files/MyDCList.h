#pragma once
#include "MyNumber.h"

class NodeDC {
public:
	// constructor
	NodeDC(){
		data = new MyNumber();
		next = nullptr;
		previous = nullptr;
	};
	NodeDC(int d){
		data = new MyNumber(d);
		next = nullptr;
		previous = nullptr;
	}; 
	NodeDC(int d, NodeDC* nxt, NodeDC* prv){
		data = new MyNumber(d);
		next = nxt;
		previous = prv;
	};
	// destructor
	~NodeDC() {}

	MyNumber* data;
	NodeDC *next;
	NodeDC *previous;
};

class MyDCList {
public:
	MyDCList();
	~MyDCList();
	bool Search(int a);

	void Insert(int a);
	void InsertMiddle(int a);
	void InsertMiddle1(int a);

	void InsertHead(int a);
	void InsertTail(int a);
	void InsertPosition(int pos, int a);
	void DeleteHead();
	void DeleteTail();
	void DeletePosition(int pos);
	void DeleteMiddle(int a);
	void DeleteMiddle1(int a);

	void Display();
	void DisplayDC();
	int GetSize() { return n;  }
	
	// void GetNext() { 
	// 	iterator_start = iterator_start->next;
	// }
	// MyNumber GetIterator() { 
	// 	return iterator_start->data;
	// }
	// void SetStartIterator(int start) {
	// 	iterator_start = Search(start);
	// }
	// void SetEndIterator(int end) {
	// 	iterator_end = Search(end);
	// }
	// void SetIterator(int start, int end) {
	// 	iterator_start = Search(start);
	// 	iterator_end = Search(end);
	// }
	// bool IsFinishedIterator() {
	// 	return (iterator_start == iterator_end);
	// }

private:
	NodeDC *head, *tail;
	NodeDC *iterator_start, *iterator_end;
	int n;
	int index;
};

extern void MyDCListExample01();