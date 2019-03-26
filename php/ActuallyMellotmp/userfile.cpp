#include <iostream>
using namespace std;

class MyArray {
public:
    int step; // number of steps

    // constructor
	MyArray(){
        a = NULL;
	    n = 0;
    };
	MyArray(int n){
        cout << "calling size initialization constructor" << endl; 
        a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = 0;
    };
	// destructor
	~MyArray(){
        delete[] a;
    };

	// Accessor + Modifiers
	int GetSize() const {
        return n;
    };

	bool Find(int x){
        for (int i = 0; i < n; i++) {
            if (a[i] == x) {
                return true;
            }
        }
        return false;
    };
	void Delete(int x);
	void Insert(int x){
        int* a1 = new int[n + 1];
        for (int i = 0; i < n; i++) {
            a1[i] = a[i];
        }
        a1[n] = x;
        delete[] a;
        a = a1;
        n++;
    };
	bool Search(int x){
        for (int i = 0; i < n; i++) {
            if (a[i] == x) {
                return true;
            }
        }
        return false;
    };

	void Invert(){
        int tmp;
        for (int i = 0; i < n/2; i++) {
            tmp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = tmp;
        }
    };

    void Display() {
	for (int i = 0; i < n; i++) {
		cout << "Element " << i << " with value " << a[i] << endl;
	}
	cout << endl;
}


	int GetMax(){
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
        };
	int GetMin(){
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
    };

	// Sorting functions
	bool IsSorted(){
        bool output = true;
        if ((n == 0) || (n==1))
            return true;
        else {
            int i = 1;
            while ((a[i - 1] < a[i]) && (i<n))
                i++;
            return (i==n);
        }
    };
	void SwapIndex(int i, int j){
        int tmp = a[i];
	    a[i] = a[j];
	    a[j] = tmp;
    };
    void SwapIndex(int* a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

	// Init functions
	void InitRandom(int v){
        for (int i = 0; i < n; i++)
		a[i] = rand() % v;
    };
	void InitSortedAscending(int v){
        if (n > 0) {
            a[0] = rand() % v;
            for (int i = 1; i < n; i++)
                a[i] = a[i - 1] + rand() % v;
	    }
    };
	void InitSortedDescending(int v){
        if (n > 0) {
            a[0] = rand() % v;
            for (int i = 1; i < n; i++)
                a[i] = a[i - 1] - rand() % v;
	    }
    };

	// Sorting algorithms
	void SelectionSort(){
        // step = 0;
        // // Invariant: the whole array is sorted between position 0 and i
        // for (int i = 0; i <n; ++i) {
        //     int min = i; // min = index of the minimum value for the array between 
        //     for (int j = i + 1; j < n; ++j) { // search for the minimum index j between i and n-1
        //         if (a[j] < a[min]) {
        //             min = j;
        //         }
        //         step++;
        //     }
        //     SwapIndex(i, min);
        // }/* Enter Code Here*/
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
    }};
	void InsertionSort(){
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
    };
	void BubbleSort(){
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
    };
	void BubbleOptSort(){
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
    };

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
	void MergeSort(){
        step = 0;
	    mergesort(a, 0, n - 1);
    };

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
        return j; // index of the pivot, which can move !
    }

    void quicksort(int* a, int start, int end) {
        if (start < end) {
            int pivot_index = partition(a, start, end);
            quicksort(a,start, pivot_index -1);
            quicksort(a, pivot_index +1,end);
        }
    }
	void QuickSort(){
        step = 0;
	    quicksort(a, 0, n - 1);
    };

private:
	int* a; // array
	int n; // size of the array
};


int main(){
    MyArray* arr = new MyArray(15);
    
    arr->Display();
    cout << arr->GetSize();

    arr->Insert(424);
    cout << arr->GetSize();

return 0;
}