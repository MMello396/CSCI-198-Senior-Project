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
        // }