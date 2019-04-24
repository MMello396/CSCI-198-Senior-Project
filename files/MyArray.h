#pragma once
#include <chrono>
#include <string>
#include "MyNumber.h"

class MyArray {
public:
	// constructor
	MyArray();
	MyArray(int n);
	// destructor
	~MyArray();

	// Accessors and Modifiers
	int GetSize() const;
	MyNumber GetElement(int i) const;
	void SetElement(int i, MyNumber x);

	bool Find(MyNumber x);
	pair<bool, int> BinarySearch1(MyNumber x);
	pair<bool, int> BinarySearch2(MyNumber x);
	void Delete(MyNumber x);
	void Insert(MyNumber x);
	bool Search(MyNumber x);
	void Display();
	void Display(int low, int high);
	void DisplayFile();
	void DisplayFileC();

	void Invert();
	MyArray* FindOdd();

	MyNumber GetMax();
	pair<MyNumber, int> GetMaxArg();
	MyNumber GetMin();
	pair<MyNumber, int> GetMinArg();
	double GetAverage();
	double GetStandardDeviation();

	MyNumber& operator[] (unsigned i);
	MyArray* operator+(const MyArray* a);

	// Copies the two arrays of MyNumbers
	int operator=(MyArray* b){
		for (int i = 0; i < n; i++)
		a[i] = b->a[i];
	};

	// Checks to see if two MyArrays are equal
	friend bool operator==(MyArray &a, MyArray &b){
		int n = a.GetSize();
		for (int i = 0; i < n; i++)
		a[i] == b[i];
	}

	// Stats
	void Reset();
	void DisplayStats();
	int TotalComps();
	int TotalAssigns();
	void Copy(MyArray* b);
	bool CheckSame(MyArray* b);

	// Sorting functions
	bool IsSorted();
	void SwapIndex(int i, int j);
	void DisplayStep(string f);
	
	// Init functions
	void InitRandom(int v);
	void InitSortedAscending(int v);
	void InitSortedDescending(int v);

	// Sorting algorithms
	void SelectionSort();
	void InsertionSort();
	void BubbleSort();
	void BubbleOptSort();
	void MergeSort();
	void QuickSort();

	// User defined sorting algorithms
	void MySelectionSort();
	void MyInsertionSort();
	void MyBubbleSort();
	void MyBubbleOptSort();
	void MyMergeSort();
	void MyQuickSort();

private:
	MyNumber* a; // array
	int n; // size of the array
};
