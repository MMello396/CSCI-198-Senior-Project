#pragma once

class NodeDC {
public:
	// constructor
	NodeDC(){
		data = 0;
		next = nullptr;
		previous = nullptr;
	};
	NodeDC(int d){
		data = d;
		next = nullptr;
		previous = nullptr;
	}; 
	NodeDC(int d, NodeDC* nxt, NodeDC* prv){
		data = d;
		next = nxt;
		previous = prv;
	};
	// destructor
	~NodeDC() {}

	int data;
	NodeDC *next;
	NodeDC *previous;
};

class MyDCList {
private:
	NodeDC *head, *tail;
	int n;

public:
	MyDCList();
	~MyDCList();
	bool IsSorted();
	bool Search(int a);
	int GetSize() { return n;  }
	void Display();
	void DisplayDC();
	NodeDC* GetHead();
	NodeDC* GetTail();

	// System defined functions
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
	
	// User defined functions
	void MyInsert(int a);
	void MyInsertMiddle(int a);
	void MyInsertMiddle1(int a);
	void MyInsertHead(int a);
	void MyInsertTail(int a);
	void MyInsertPosition(int pos, int a);
	void MyDeleteHead();
	void MyDeleteTail();
	void MyDeletePosition(int pos);
	void MyDeleteMiddle(int a);
	void MyDeleteMiddle1(int a);

	
};

extern void MyDCListExample01();