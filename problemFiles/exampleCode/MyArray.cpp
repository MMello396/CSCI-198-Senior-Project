#include "MyArray.h"
#include <iostream>
using namespace std;

int step; // number of steps

MyArray::MyArray() {
	a = NULL;
	n = 0;
}

MyArray::MyArray(int n1) {
	n = n1;
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = 0;
}

MyArray::~MyArray() {
	delete[] a;
}

int MyArray::GetSize() const { return n; }

int MyArray::GetElement(int i) const {
	if (i < 0) {
		cout << "Too small index";
		exit(EXIT_FAILURE);
	} else if (i >= n) {
		cout << "Too large index";
		exit(EXIT_FAILURE);
	} else
		return a[i];
}

void MyArray::SetElement(int i, int x) {
	a[i] = x;
}

int& MyArray::operator[] (unsigned i) {
	try	{
		return a[i];
	} catch (exception& e) {
		cout << "Problem with index" << e.what() << endl;
	}		
}

MyArray* MyArray::operator+(const MyArray* a)  {
	MyArray* out = new MyArray(this->n + a->GetSize());
	for (int i = 0; i < this->n; i++)
		out->SetElement(i, this->GetElement(i));
	for (int i = this->n; i < out->GetSize(); i++)
		out->SetElement(i+ this->n, a->GetElement(i));
	return out;
}


bool MyArray::Find(int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return true;
		}
	}
	return false;
}


void MyArray::Insert(int x) {
	int* a1 = new int[n + 1];
	for (int i = 0; i < n; i++) {
		a1[i] = a[i];
	}
	a1[n] = x;
	delete[] a;
	a = a1;
	n++;
}

void MyArray::Invert() {
	int tmp;
	for (int i = 0; i < n/2; i++) {
		tmp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = tmp;
	}
}

MyArray* MyArray::FindOdd() {
	int nodd = 0;
	for (int i = 0; i < n; i++) {
		if (((int)a[i] % 2) == 1)
			nodd++;
	}
	nodd = 0;
	MyArray* a1 = new MyArray(nodd);
	for (int i = 0; i < n; i++) {
		if (((int)a[i] % 2) == 1) {
			a1->SetElement(nodd, a[i]);
			nodd++;
		}
	}
	return a1;
}

bool MyArray::Search(int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return true;
		}
	}
	return false;
}

int MyArray::GetMax() {
	if (n > 0) {
		int max = a[0];
		for (int i = 1; i < n; i++) {
			if (a[i] > max)
				max = a[i];
		}
		return max;
	}
	else
		return 0;
}

int MyArray::GetMin() {
	if (n > 0) {
		int min = a[0];
		for (int i = 1; i < n; i++) {
			if (a[i] < min)
				min = a[i];
		}
		return min;
	}
	else
		return 0;
}

double MyArray::GetAverage() {
	double result = 0;
	if (n > 0) {
		for (int i = 0; i < n; i++)
			result += (double)a[i];
		result /= n;
	}
	return result;
}

double MyArray::GetStandardDeviation() {
	double result = 0;
	if (n > 0) {
		double mean = GetAverage();
		for (int i = 0; i < n; i++) {
			double tmp = (double)a[i] - mean;
			result += tmp*tmp;
		}
		result /= n;
		result = sqrt(result);
	}
	return result;
}

// C++ programming
void MyArray::Display() {
	for (int i = 0; i < n; i++) {
		cout << "Element " << i << " with value " << a[i] << endl;
	}
	cout << endl;
}

void Display(int *a, int start, int end) {
	for (int i = start; i <=end; i++) {
		cout << "Element " << i << " with value " << a[i] << endl;
	}
	cout << endl;
}

void MyArray::Display(int low,int high) {
	if (low<0 || high>(n - 1))
		exit(EXIT_FAILURE);
	else 
		for (int i = low; i <= high; i++)
			cout << "Element " << i << " with value " << a[i] << endl;
}

// Sorting Algorithm
bool MyArray::IsSorted() {
	bool output = true;
	if ((n == 0) || (n==1))
		return true;
	else {
		int i = 1;
		while ((a[i - 1] < a[i]) && (i<n))
			i++;
		return (i==n);
	}
}

void MyArray::InitRandom(int v) {
	for (int i = 0; i < n; i++)
		a[i] = rand() % v;
}

void MyArray::InitSortedAscending(int v) {
	if (n > 0) {
		a[0] = rand() % v;
		for (int i = 1; i < n; i++)
			a[i] = a[i - 1] + rand() % v;
	}
}

void MyArray::InitSortedDescending(int v) {
	if (n > 0) {
		a[0] = rand() % v;
		for (int i = 1; i < n; i++)
			a[i] = a[i - 1] - rand() % v;
	}
}

void MyArray::SwapIndex(int i, int j) {
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void SwapIndex(int* a, int i, int j) {
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void MyArray::SelectionSort() {
	step = 0;
	// Invariant: the whole array is sorted between position 0 and i
	for (int i = 0; i <n; ++i) {
		int min = i; // min = index of the minimum value for the array between 
		for (int j = i + 1; j < n; ++j) { // search for the minimum index j between i and n-1
			if (a[j] < a[min]) {
				min = j;
			}
			step++;
		}
		SwapIndex(i, min);
	}
}

void MyArray::InsertionSort() {
	step = 0;
	// Invariant: the array defined between position 0 and i is sorted
	bool done;
	for (int i = 0; i < n; ++i) {
		int j = i + 1;
		done = false;
		while ((j > 0) && (!done)) { 
			step++;
			if (a[j] < a[j - 1]) {
				SwapIndex(j, j - 1);
			}
			else
				done=true;
			j--;
		}
	}
}

void MyArray::BubbleSort() {
	step = 0;
	// Invariant: the whole array is sorted between n-1-i and n-1
	for (int i = 0; i < n-1; ++i) {
		for (int j = 0; j < n-i-1; ++j) {
			step++;
			if (a[j] > a[j + 1]) {
				SwapIndex(j, j + 1);
			}
		}
	}
}

void MyArray::BubbleOptSort() {
	step = 0;
	// Invariant: the whole array is sorted between n-1-i and n-1
	bool sorted=false;
	int i = 0;
	while ((i<n-1) && (!sorted)) {
		sorted = true; // we assume the array is sorted between 0 and n-i-1
		for (int j =0 ; j < n-i-1; j++) {
			step++;
			if (a[j]>a[j+1]) {
				SwapIndex(j,j+1);
				sorted = false;
			}
		}
		i++;
	}
}

void merge(int* a, int start, int mid, int end) {
	// Init a1
	int n1 = mid - start +1; 
	int* a1 = new int[n1];
	for (int i = 0; i < n1; i++)
		a1[i] = a[i+start];
	// Init a2
	int n2 = end - mid;
	int* a2 = new int[n2];
	for (int i = 0; i < n2; i++)
		a2[i] = a[i+mid+1];

	int i1 = 0;
	int i2 = 0;
	int i3 = start;
	while ((i1 < n1) && (i2 < n2)) {
		if (a1[i1] < a2[i2]) {
			a[i3] = a1[i1];
			i1++;
		}
		else {
			a[i3] = a2[i2];
			i2++;
		}
		i3++;
		step++;
	}
	if (i1 < n1) // -> we left the while loop because i2>=n2
		for (int i = i1; i < n1; i++) {
			a[i3] = a1[i];
			i3++;
			step++;
		}
	else // -> we left the while loop because i1>=n1
		for (int i = i2; i < n2; i++) {
			a[i3] = a2[i];
			i3++;
			step++;
		}
	delete[] a1;
	delete[] a2;
}

void mergesort(int* a, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergesort(a, start, mid);
		mergesort(a, mid + 1, end);
		merge(a, start, mid, end);
	}
}

void MyArray::MergeSort() {
	step = 0;
	mergesort(a, 0, n - 1);
}

// Hoare partition
int partition(int* a, int start, int end) {
	int i = start;
	int j = end;
	int pivot_value = a[(start+end)/2]; // in the middle
	bool finished = false;
	while (!finished) { 
		while ((i<end) && (a[i] <= pivot_value)) {
			i++; // move to the right
			step++;
		}
		while ((j>start) && (a[j] > pivot_value)) {
			j--; // move to the left
			step++;
		}
		if (i < j)
			SwapIndex(a,i,j);
		else
			finished = true;
	}
	cout << "Pivot: " << pivot_value << " at position " << j << endl;
	Display(a, start, end);
	return j; // index of the pivot, which can move !
}

void quicksort(int* a, int start, int end) {
	if (start < end) {
		int pivot_index = partition(a, start, end);
		quicksort(a,start, pivot_index -1);
		quicksort(a, pivot_index +1,end);
	}
}

void MyArray::QuickSort() {
	step = 0;
	quicksort(a, 0, n - 1);
}

/////////////////////////////////////////////////
// Miscelaneous functions

void Search_v01(int* a, int n,int x) {
	bool find = false;
	int argx = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] > x) {
			find = true;
			argx = i;
			break;
		}
	}
	if (find)
		cout << "Found " << a[argx] << endl;
	else
		cout << "Not found" << endl;
}
void Search_v02(int* a, int n, int x) {
	bool find = false;
	int argx = -1, i = 0;
	while ((!find) && (i < n)) {
		if (a[i] > x) {
			find = true;
			argx = i;
		}
		i++;
	}
	if (find)
		cout << "Found " << a[argx] << endl;
	else
		cout << "Not found" << endl;
}
void Search_v03(int* a, int n, int x) {
	bool find = false;
	int argx = -1, i = 0;
	do {
		if (a[i] > x) {
			find = true;
			argx = i;
		}
		i++;
	} while ((!find) && (i < n));
	if (find)
		cout << "Found " << a[argx] << endl;
	else
		cout << "Not found" << endl;
}

void MyArrayExample00() {
	int n = 10, x = 100;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = rand() % 200;
	Search_v01(a, n, x);
	Search_v02(a, n, x);
	Search_v03(a, n, x);
}


// a and n are just as input!
void f1(int* a,int n) {
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = i;
}

// a is input/output and n as input
// we modify the link to *a which is **a
void f2(int** a, int n) {
	*a = new int[n];
	for (int i = 0; i < n; i++)
		(*a)[i] = i;
}

int* f3(int n) {
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = i;
	return a;
}


void DisplayArray(int* a, int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << ",";
	cout << endl;
}

void MyArrayExample01() {
	int n = 10;
	int* a = NULL;
	cout << "Evaluate f1" << endl;
	f1(a,n);
	//DisplayArray(a,n); // not working because a has nothing !
	cout << "Evaluate f2" << endl;
	f2(&a,n);
	DisplayArray(a, n);
	cout << "Evaluate f3" << endl;
	a = NULL;
	a=f3(n);
	DisplayArray(a, n);
}

void MyArrayExample02() {

	// Reference example
	int x = 25;
	int &y = x;
	y = 12;

	cout << "x:" << x << endl;
	cout << "y:" << x << endl;

	// Increment example
	int i = 3;
	cout << i++ << endl;
	int j = 3;
	cout << ++j << endl;

	// Pointer shifting example
	int n = 10;
	int* a1 = new int[n];
	for (int i = 0; i < n; i++)
		a1[i] = i * 2;
	int* b1 = a1;
	cout << b1[2] << endl;
	cout << *(b1+3) << endl;

}




// Basic sorting algorithms
void MyArrayExample04() {
	int nsize = 10;
	MyArray* A = new MyArray(nsize);
	int type_array = 0;
	for (int type_sort = 1; type_sort <=6; type_sort++) {
		// Create a new array at each iteration!
		if (type_array == 0) {
			A->InitRandom(2);
			cout << "Random array" << endl;
		}
		else if (type_array == 1) {
			A->InitSortedAscending(nsize*nsize);
			cout << "Sorted array" << endl;
		}
		if (nsize < 15) {
			cout << "Input array:" << endl;
			A->Display();
		}
		auto t1 = chrono::high_resolution_clock::now();
		switch (type_sort) {
		case 1: // Selection sort
			cout << "Selection sort" << endl;
			A->SelectionSort();
			break;
		case 2: // Insertion sort
			cout << "Insertion sort" << endl;
			A->InsertionSort();
			break;
		case 3: // Bubble sort
			cout << "Bubble sort" << endl;
			A->BubbleSort();
			break;
		case 4: // Bubble Opt sort
			cout << "Bubble Opt sort" << endl;
			A->BubbleOptSort();
			break;
		case 5: // Merge sort
			cout << "Mergesort" << endl;
			A->MergeSort();
			break;
		case 6: // Quick sort
			cout << "Quicksort" << endl;
			A->QuickSort();
			break;
		}
		if (nsize<15)
			A->Display();
		auto t2 = chrono::high_resolution_clock::now();
		chrono::duration<double,milli> duration_ms = t2 - t1;
		cout << "It took " << duration_ms.count() << " ms" << endl;
	}
}

// Mergesort and Quicksort
void MyArrayExample05() {

	int nsize = 12;
	MyArray* A = new MyArray(nsize);
	//A->InitRandom(nsize*nsize);
	//cout << "Mergesort" << endl;
	//A->MergeSort();
	//A->Display();

	A->InitRandom(2);
	cout << "Quicksort" << endl;
	A->QuickSort();
	A->Display();

}