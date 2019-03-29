#pragma once

class NodeDC {
public:
	NodeDC(): 
			data(0), next(NULL), previous(NULL) {}
	NodeDC(MyType d): 
			data(d), next(NULL), previous(NULL) {}
	NodeDC(MyType d,NodeDC* nxt,NodeDC* prv):
			data(d), next(nxt), previous(prv) {}
	~NodeDC() {}
	MyType data;
	NodeDC *next;
	NodeDC *previous;
};

class MyDCList {
public:
	MyDCList();
	~MyDCList();
	NodeDC* Search(int j);
	bool Search(MyType value);

	void Insert(MyType value);
	void InsertMiddle(MyType value);
	void InsertMiddle1(MyType value);

	void InsertHead(MyType value);
	void InsertTail(MyType value);
	void InsertPosition(int pos, MyType value);
	void DeleteHead();
	void DeleteTail();
	void DeletePosition(int pos);
	void DeleteMiddle(MyType value);
	void DeleteMiddle1(MyType value);

	void Display();
	void DisplayDC();
	void DisplayFile();
	int GetSize() { return n;  }
	
	void GetNext() { 
		iterator_start = iterator_start->next;
	}
	MyType GetIterator() { 
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