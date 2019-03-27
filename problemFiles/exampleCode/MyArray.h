#pragma once
#include <chrono>
#include <string>

class MyArray {
public:
	// constructor
	MyArray();
	MyArray(int n);
	// destructor
	~MyArray();

	// Accessor + Modifiers
	int GetSize() const;
	int GetElement(int i) const;
	void SetElement(int i, int x);

	bool Find(int x);
	void Delete(int x);
	void Insert(int x);
	bool Search(int x);
	void Display();
	void Display(int low, int high);
	void DisplayFile();
	void DisplayFileC();

	void Invert();
	MyArray* FindOdd();

	int GetMax();
	int GetMin();
	
	double GetAverage();
	double GetStandardDeviation();

	int& operator[] (unsigned i);
	MyArray* operator+(const MyArray* a);

	// Sorting functions
	bool IsSorted();
	void SwapIndex(int i, int j);

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

private:
	int* a; // array
	int n; // size of the array
};

extern void MyArrayExample00();
extern void MyArrayExample001();
extern void MyArrayExample01();
extern void MyArrayExample02();
extern void MyArrayExample03();
extern void MyArrayExample04();
extern void MyArrayExample05();
