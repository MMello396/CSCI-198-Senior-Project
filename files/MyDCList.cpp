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

NodeDC* MyDCList::GetHead(){
	return head;
}

NodeDC* MyDCList::GetTail(){
	return tail;
}

bool MyDCList::structureGood(){

	NodeDC *currentHead = head;
	NodeDC *currentTail = tail;

	int i = 0;
	// case of no nodes in the list
	if (head == tail) return true;

	while (i < n){
		
		if(currentHead->next != NULL) currentHead = currentHead->next;
	
		if (currentTail->previous != NULL) currentTail = currentTail->previous;
		i++;
	}

	if (i == n) {
		return true;
	} else {
		return false;
	}
}

bool MyDCList::isSame(MyDCList* otherList)
{
	bool isSame = false;

	NodeDC *oListCurrent = otherList->head;
	NodeDC *current = head;
	int i = 0;
	while (i < n)
	{
		if (current != NULL){
			if (oListCurrent->data == current->data){
				oListCurrent = oListCurrent->next;
				current = current->next;
				i++;
			} else {
				return false;
			}
		}
	}
	return true;
}

bool MyDCList::IsSorted()
{
	NodeDC *cursor = head;
	bool sorted = true;
	int i = 0;
	while ((sorted != false) && (i < n))
	{
		if (cursor->data >= cursor->next->data)
			sorted = false;
	}
	return sorted;
}

bool MyDCList::Search(int x)
{
	NodeDC *cursor = head;
	bool found = false;
	int i = 0;
	while ((found != true) && (i < n))
	{
		if (cursor->data == x)
			found = true;
		else
			cursor = cursor->next;
	}
	return found;
}

void MyDCList::InsertTail(int value)
{
	NodeDC *tmp = new NodeDC(value);
	if (head == NULL)
	{
		head = tmp;
		tail = tmp;
	}
	else
	{
		tail->next = tmp;
		tmp->previous = tail;
		tail = tmp;
	}
	n++;
}

void MyDCList::InsertHead(int value)
{
	NodeDC *tmp = new NodeDC(value, head, NULL);
	if (head == NULL)
	{
		head = tmp;
		tail = tmp;
	}
	else
	{
		head->previous = tmp;
		head = tmp;
	}
	n++;
}

// default insert
void MyDCList::Insert(int value)
{
	InsertHead(value);
}

void MyDCList::InsertPosition(int pos, int value)
{
	NodeDC *pre = new NodeDC;
	NodeDC *cur = new NodeDC;
	NodeDC *tmp = new NodeDC;
	cur = head;
	for (int i = 1; i < pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	tmp->data = value;
	pre->next = tmp;
	tmp->next = cur;
	n++;
}

void MyDCList::InsertMiddle(int value)
{
	NodeDC *tmp = new NodeDC(value);
	NodeDC *cursor = head;
	if (head == NULL)
	{ // insert to the head
		cout << "Insert to head/tail: " << value << endl;
		head = tmp;
		tail = tmp;
	}
	else if (head->data > value)
	{ // insert to the head
		cout << "Insert to head: " << value << endl;
		head->previous = tmp;
		tmp->next = head;
		head = tmp;
	}
	else
	{
		NodeDC *prev = head;
		NodeDC *cursor = head->next;
		while ((cursor != NULL) && (cursor->data < value))
		{
			prev = prev->next;
			cursor = cursor->next;
		}
		if (cursor == NULL)
		{ // insert to the tail
			cout << "Insert to tail: " << value << endl;
			prev->next = tmp;
			tmp->previous = prev;
			tail = tmp;
		}
		else
		{
			cout << "Insert middle: " << value << endl;
			prev->next = tmp;
			tmp->previous = prev;
			tmp->next = cursor;
			cursor->previous = tmp;
		}
	}
	n++;
}

void InsertMiddleDC(NodeDC * *head, NodeDC * prev, NodeDC * *tail, int value)
{
	if ((*head) == NULL)
	{
		cout << "Insert to head/tail: " << value << endl;
		NodeDC *tmp = new NodeDC(value);
		*head = tmp;
		*tail = tmp;
	}
	else if ((*head)->data > value)
	{
		cout << "Insert to head: " << value << endl;
		NodeDC *tmp = new NodeDC(value);
		(*head)->previous = tmp;
		tmp->next = (*head);
		(*head) = tmp;
		if (prev != NULL)
		{
			cout << "Insert to middle: " << value << endl;
			tmp->previous = prev;
			prev->next = tmp;
		}
	}
	else
		InsertMiddleDC(&(*head)->next, (*head), tail, value);
}

void MyDCList::InsertMiddle1(int value)
{
	InsertMiddleDC(&head, NULL, &tail, value);
	n++;
}

void MyDCList::DeleteMiddle(int value)
{
	if (head->data == value)
	{ // remove to the head
		cout << "Remove to head: " << value << endl;
		NodeDC *tmp = head;
		head = head->next;
		head->previous = NULL;
		delete tmp;
	}
	else
	{
		NodeDC *cursor = head;
		NodeDC *prev = cursor->previous;
		while ((cursor != NULL) && (cursor->data != value))
		{
			prev = cursor;
			cursor = cursor->next;
		}
		if (cursor != NULL)
		{ // remove
			if (cursor->next == NULL)
			{ // it is the tail
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

void DeleteMiddleDC(NodeDC * *head, NodeDC * *tail, int value)
{
	if ((*head) != NULL)
	{
		if ((*head)->data == value)
		{ // remove to the head
			NodeDC *tmp = *head;
			*head = (*head)->next;
			if ((*head) == NULL)
				*tail = tmp->previous;
			else
				(*head)->previous = tmp->previous;
			delete tmp;
		}
		else
			DeleteMiddleDC(&(*head)->next, tail, value);
	}
}

void MyDCList::DeleteMiddle1(int value)
{
	DeleteMiddleDC(&head, &tail, value);
	n--;
}

void MyDCList::DeleteHead()
{
	if (head == tail && head != NULL)
	{
		head = NULL;
		tail = NULL;
		n--;
	}
	else if (head != NULL)
	{
		NodeDC *tmp = new NodeDC;
		tmp = head;
		head = head->next;
		head->previous = NULL;
		delete tmp;
		n--;
	}
}

void MyDCList::DeleteTail()
{
	NodeDC *current = head;
	NodeDC *previous = NULL;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	tail = previous;
	previous->next = NULL;
	delete current;
	n--;
}

void MyDCList::DeletePosition(int pos)
{
	if (pos == 0)
		DeleteHead();
	else if (pos == n - 1)
		DeleteTail();
	else
	{
		NodeDC *current = head;
		NodeDC *previous = NULL;
		for (int i = 1; i <= pos; i++)
		{
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		current->next->previous = previous;
		delete current;
		n--;
	}
}

void MyDCList::Display()
{
	NodeDC *tmp = new NodeDC;
	tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->data << "\n";
		tmp = tmp->next;
	}
}

void MyDCList::DisplayDC()
{
	NodeDC *tmp;
	tmp = head;
	int data_prev, data_next, data_head, data_tail;
	cout << "List of size :" << n << endl;
	if (head != NULL)
		data_head = head->data;
	else
		data_head = -1;
	if (tail != NULL)
		data_tail = tail->data;
	else
		data_tail = -1;
	cout << "Head:" << data_head << endl;
	cout << "Tail:" << data_tail << endl;
	while (tmp != NULL)
	{
		if (tmp->previous != NULL)
			data_prev = tmp->previous->data;
		else
			data_prev = -1;
		if (tmp->next != NULL)
			data_next = tmp->next->data;
		else
			data_next = -1;
		cout << "(" << data_prev << "," << tmp->data << "," << data_next << ")" << endl;
		tmp = tmp->next;
	}
}
