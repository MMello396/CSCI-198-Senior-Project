#include "MyArray.h"
#include "MyNumber.h"
#include <iostream>
// #include <fstream>
// #include <tuple>
#include <cstdlib>

using namespace std;

int step; // number of steps

MyArray::MyArray() {
	a = NULL;
	n = 0;
}

MyArray::MyArray(int n1) {
	n = n1;
	a = new MyNumber[n];
	for (int i = 0; i < n; i++)
		a[i] = 0;
}

MyArray::~MyArray() {
	delete[] a;
}

int MyArray::GetSize() const { return n; }

MyNumber MyArray::GetElement(int i) const {
	if (i < 0) {
		cout << "Too small index";
		exit(EXIT_FAILURE);
	} else if (i >= n) {
		cout << "Too large index";
		exit(EXIT_FAILURE);
	} else
		return a[i];
}

void MyArray::SetElement(int i, MyNumber x) {
	a[i] = x;
}

MyNumber& MyArray::operator[] (unsigned i) {
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

bool MyArray::Find(MyNumber x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return true;
		}
	}
	return false;
}

pair<bool, int> MyArray::BinarySearch1(MyNumber x) {
	bool found = false;
	int mid,low = 0, high = n-1;
	while ((low <= high) && (!found)) {
		mid = (low + high) / 2;
		if (x==a[mid])
			return make_pair(true,mid);
		else {
			if (x < a[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
	return make_pair(false, -1);
}

// C++ programming
void MyArray::Display() {
	for (int i = 0; i < n; i++) {
		cout << "Element " << i << " with value " << a[i].value() << endl;
	}
	cout << endl;
}

// Stats
void MyArray::Reset(){
	for (int i = 0; i < n; i++)
		a[i].ResetStats();
}

void MyArray::DisplayStats(){
	for (int i = 0; i < n; i++)
		a[i].DisplayInfo();
}

int MyArray::TotalComps(){
	int comps = 0;
	for (int i = 0; i < n; i++)
		comps += a[i].GetComps();
	return comps;
}

int MyArray::TotalAssigns(){
	int assigns = 0;
	for (int i = 0; i < n; i++)
		assigns += a[i].GetAssigns();
	return assigns;
}

void MyArray::Copy(MyArray* b){
	for (int i = 0; i < n; i++)
		a[i] = b->a[i];
}

bool MyArray::CheckSame(MyArray* b){
	bool same = false;
	int i;
	for (i = 0; i < n; i++)
		a[i] == b->a[i];
	if(i == n) return true;
	return false;
}

// Sorting Algorithm
bool MyArray::IsSorted() {
	bool output = true;
	if ((n == 0) || (n==1))
		return true;
	else {
		int i = 1;
		while ((a[i - 1].value() <= a[i].value()) && (i < n))
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

void MyArray::DisplayStep(string f) {
	cout << "Array of size " << n << endl;
	cout << "Number of steps for " << f << " is " << step << endl;
}

void MyArray::SwapIndex(int i, int j) {
	MyNumber tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void SwapIndex(MyNumber* a, int i, int j) {
	MyNumber tmp = a[i];
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
	// DisplayStep(__func__);
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
	// DisplayStep(__func__);
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
	// DisplayStep(__func__);
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
	// DisplayStep(__func__);
}

void merge(MyNumber* a, int start, int mid, int end) {
	// Init a1
	int n1 = mid - start +1; 
	MyNumber* a1 = new MyNumber[n1];
	for (int i = 0; i < n1; i++)
		a1[i] = a[i+start];
	// Init a2
	int n2 = end - mid;
	MyNumber* a2 = new MyNumber[n2];
	for (int i = 0; i < n2; i++)
		a2[i] = a[i+mid+1];

	int i1 = 0;
	int i2 = 0;
	int i3 = start;
	while ((i1 < n1) && (i2 < n2)) {
		if (a1[i1] < a2[i2] ) {
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

void mergesort(MyNumber* a, int start, int end) {
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
	// DisplayStep(__func__);
}

// Hoare partition
int partition(MyNumber* a, int start, int end) {
	int i = start;
	int j = end;
	MyNumber pivot_value = a[(start+end)/2]; // in the middle
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
	cout << "Pivot: " << pivot_value.value() << " at position " << j << endl;
	// Display(a, start, end);
	return j; // index of the pivot, which can move !
}

void quicksort(MyNumber* a, int start, int end) {
	if (start < end) {
		int pivot_index = partition(a, start, end);
		quicksort(a,start, pivot_index -1);
		quicksort(a, pivot_index +1,end);
	}
}

void MyArray::QuickSort() {
	step = 0;
	quicksort(a, 0, n - 1);
	// DisplayStep(__func__);
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

void DisplayArray(int* a, int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << ",";
	cout << endl;
}