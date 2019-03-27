#pragma once

class NodeDC {
public:
	int data;
	NodeDC *next;
	NodeDC *previous;
	NodeDC(): 
			data(0), next(nullptr), previous(nullptr) {}
	NodeDC(int d): 
			data(d), next(nullptr), previous(nullptr) {}
	NodeDC(int d,NodeDC* nxt,NodeDC* prv):
			data(d), next(nxt), previous(prv) {}
	~NodeDC() {}
	
};

class MyDCList {
public:
	MyDCList();
	~MyDCList();
	NodeDC* Search(int j);
	bool search(int value);

	void Insert(int value);
	void InsertMiddle(int value);
	void InsertMiddle1(int value);

	void InsertHead(int value);
	void InsertTail(int value);
	void InsertPosition(int pos, int value);
	void DeleteHead();
	void DeleteTail();
	void DeletePosition(int pos);
	void DeleteMiddle(int value);
	void DeleteMiddle1(int value);

	void Display();
	void DisplayDC();
	void DisplayFile();
	int GetSize() { return n;  }
	
	void GetNext() { 
		iterator_start = iterator_start->next;
	}
	int GetIterator() { 
		return iterator_start->data;
	}
	void SetStartIterator(int start) {
		iterator_start = Search(start);
	}
	void SetEndIterator(int end) {
		iterator_end = Search(end);
	}
	void SetIterator(int start, int end) {
		iterator_start = Search(start);
		iterator_end = Search(end);
	}
	bool IsFinishedIterator() {
		return (iterator_start == iterator_end);
	}

private:
	NodeDC *head, *tail;
	NodeDC *iterator_start, *iterator_end;
	int n;
	int index;
};

extern void MyDCListExample01();