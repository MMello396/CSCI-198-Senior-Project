// #include "stdafx.h"
#include "MyDCList.h"
#include <iostream>

using namespace std;

MyDCList::MyDCList() {
	head = NULL;
	tail = NULL;
	n = 0;
}
MyDCList::~MyDCList() {
	NodeDC *current = head;
	while (current) {
		NodeDC *next = current->next;
		delete current;
		current = next;
	}
}

bool MyDCList::Search(int x) {
	NodeDC *cursor = head;
	bool found = false;
	int i = 0;
	while ((found!=true) && (i<n)) {
		if (cursor->data->value() == x)
			found = true;
		else
			cursor = cursor->next;
	}
	return found;
}


void MyDCList::InsertTail(int value) {
	NodeDC *tmp = new NodeDC(value);
	if (head == NULL) {
		head = tmp;
		tail = tmp;
	} 
	else {
		tail->next = tmp;
		tmp->previous = tail;
		tail = tmp;
	}
	n++;
}

void MyDCList::InsertHead(int value) {
	NodeDC *tmp = new NodeDC(value,head,NULL);
	if (head == NULL) {
		head = tmp;
		tail = tmp;
	}
	else {
		head->previous = tmp;
		head = tmp;
	}
	n++;
}

// default insert
void MyDCList::Insert(int value) {
	InsertHead(value);
}

void MyDCList::InsertPosition(int pos, int value) {
	NodeDC *pre = new NodeDC;
	NodeDC *cur = new NodeDC;
	NodeDC *tmp = new NodeDC(value);
	cur = head;
	for (int i = 1; i<pos; i++) {
		pre = cur;
		cur = cur->next;
	}
	// tmp->data->value() = value;
	pre->next = tmp;
	tmp->next = cur;
	n++;
}


void MyDCList::InsertMiddle(int value) {
	NodeDC *tmp = new NodeDC(value);
	NodeDC *cursor = head;
	if (head == NULL) { // insert to the head
		cout << "Insert to head/tail: " << value << endl;
		head = tmp;
		tail = tmp;
	}
	else if (head->data->value() > value) { // insert to the head
		cout << "Insert to head: " << value << endl;
		head->previous = tmp;
		tmp->next = head;
		head = tmp;
	}
	else {
		NodeDC *prev = head;
		NodeDC *cursor = head->next;
		while ((cursor != NULL) && (cursor->data->value() < value)) {
			prev = prev->next;
			cursor = cursor->next;
		}
		if (cursor == NULL) { // insert to the tail
			cout << "Insert to tail: " << value << endl;
			prev->next = tmp;
			tmp->previous = prev;
			tail = tmp;
		}
		else {
			cout << "Insert middle: " << value << endl;
			prev->next = tmp;
			tmp->previous = prev;
			tmp->next = cursor;
			cursor->previous = tmp;
		}
	}
	n++;
}


void InsertMiddleDC(NodeDC **head, NodeDC *prev, NodeDC **tail, int value) {
	if ((*head) == NULL) { 
		cout << "Insert to head/tail: " << value << endl;
		NodeDC *tmp = new NodeDC(value);
		*head = tmp;
		*tail = tmp;
	}
	else if ((*head)->data->value() > value) {
		cout << "Insert to head: " << value << endl;
		NodeDC *tmp = new NodeDC(value);
		(*head)->previous = tmp;
		tmp->next = (*head);
		(*head) = tmp;
		if (prev != NULL) {
			cout << "Insert to middle: " << value << endl;
			tmp->previous = prev;
			prev->next = tmp;
		}
	}
	else
		InsertMiddleDC(&(*head)->next,(*head),tail, value);
}

void MyDCList::InsertMiddle1(int value) {
	InsertMiddleDC(&head,NULL,&tail, value);
	n++;
}

void MyDCList::DeleteMiddle(int value) {
	//cout << "Delete element " << value << endl;
	if (head->data->value() == value) { // remove to the head
		cout << "Remove to head: " << value << endl;
		NodeDC *tmp = head;
		head = head->next;
		head->previous = NULL;
		delete tmp;
	}
	else {
		NodeDC *cursor = head;
		NodeDC *prev = cursor->previous;
		while ((cursor != NULL) && (cursor->data->value()!=value)) {
			prev = cursor;
			cursor = cursor->next;
		}
		if (cursor!= NULL) { // remove		
			if (cursor->next == NULL) { // it is the tail
				cout << "Remove tail: " << value << endl;
				prev->next = NULL;
				tail = prev;
			}
			else
			{
				cout << "Remove middle: " << value << endl;
				cursor->next->previous = prev;
				prev->next = cursor->next;
			}
			delete cursor;
		}
	}
	n--;
}


void DeleteMiddleDC(NodeDC **head, NodeDC **tail, int value) {
	if ((*head) != NULL) {
		if ((*head)->data == value) { // remove to the head
			NodeDC *tmp = *head;
			*head = (*head)->next;
			if ((*head)==NULL)
				*tail = tmp->previous;
			else
				(*head)->previous = tmp->previous;
			delete tmp;
		}
		else
			DeleteMiddleDC(&(*head)->next, tail, value);
	}
}

void MyDCList::DeleteMiddle1(int value) {
	DeleteMiddleDC(&head, &tail, value);
	n--;
}

void MyDCList::DeleteHead() {
	NodeDC *tmp = new NodeDC;
	tmp = head;
	head = head->next;
	head->previous = NULL;
	delete tmp;
	n--;
}

void MyDCList::DeleteTail() {
	NodeDC *current= head;
	NodeDC *previous = NULL;
	while (current->next != NULL) {
		previous = current;
		current = current->next;
	}
	tail = previous;
	previous->next = NULL;
	delete current;
	n--;
}

void MyDCList::DeletePosition(int pos) {
	if (pos == 0)
		DeleteHead();
	else if (pos==n-1)
		DeleteTail();
	else {
		NodeDC *current = head;
		NodeDC *previous = NULL;
		for (int i = 1; i <= pos; i++) {
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		current->next->previous = previous;
		delete current;
		n--;
	}
}

void MyDCList::Display() {
	NodeDC *tmp = new NodeDC;
	tmp = head;
	while (tmp != NULL) {
		cout << tmp->data->value() << "\n";
		tmp = tmp->next;
	}
}

void MyDCList::DisplayDC() {
	NodeDC *tmp;
	tmp = head;
	int data_prev, data_next, data_head, data_tail;
	cout << "List of size :" << n << endl;
	if (head != NULL)
		data_head = head->data->value();
	else
		data_head = -1;
	if (tail != NULL)
		data_tail = tail->data->value();
	else
		data_tail = -1;
	cout << "Head:" << data_head << endl;
	cout << "Tail:" << data_tail << endl;
	while (tmp != NULL) {
		if (tmp->previous != NULL)
			data_prev = tmp->previous->data->value();
		else
			data_prev = -1;
		if (tmp->next != NULL)
			data_next = tmp->next->data->value();
		else
			data_next = -1;
		cout << "(" << data_prev << "," << tmp->data << "," << data_next << ")" << endl;
		tmp = tmp->next;
	}
}

void MyDCListExample01() {
	cout << "Test the Double Chained List" << endl;
	MyDCList* LD = new MyDCList();
	LD->DisplayDC();


	LD->InsertMiddle1(5);
	LD->InsertMiddle1(2);
	LD->InsertMiddle1(3);
	LD->InsertMiddle1(1);
	LD->InsertMiddle1(15);
	LD->InsertMiddle1(50);
	LD->InsertMiddle1(-50);
	LD->InsertMiddle1(20);

	LD->DisplayDC();
	//LD->DeletePosition(0);
	//LD->DisplayDC();
	//LD->DeletePosition(6);
	//LD->DisplayDC();
	LD->DeletePosition(4);

//	LD->DeleteMiddle1(5);
//	LD->DeleteMiddle1(10);
//	LD->DeleteMiddle1(50);
//	LD->DeleteMiddle1(-50);
//	LD->DeleteMiddle1(5);
//	LD->DeleteMiddle1(20);

	LD->DisplayDC();

	delete LD;

}
