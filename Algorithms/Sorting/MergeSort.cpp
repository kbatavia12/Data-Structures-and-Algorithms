#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &A, int l, int r, int m) {
    // Divide the array into two halves and create two subarrays
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> left(n1);
    vector<int> right(n2);

    //Fill the two subarrays
    for (int i =0; i < (n1); i++) {
        left[i] = A[l + i];
    }
    
    for (int i =0; i < (n2); i++) {
        right[i] = A[m + 1 + i];
    }


    //Create 3 pointers which keep track of the left, right and the original array
    int i =0, j =0, k = l;


    //Loop until we've iterated over each element of any one array
    while(i < (n1) && j < (n2)) {
        if (left[i] <= right[j]) { 
            A[k] = left[i]; //If the ith element of the left subarray is smaller than the jth element of the right subarray,put the left array element at the kth position in the array.
            i++;
        } else {
            A[k] = right[j];
            j++;
        }

        k++;
    }

    //Iterate over the remaining elements (if any) and put it in the array
    while(i < (n1)) { 
        A[k] = left[i];
        i++;
        k++;
    }

    //Iterate over the remaining elements (if any) and put it in the array
    while(j < (n2)) {
        A[k] = right[j];
        j++;
        k++;
    }

}


void mergeSort(vector<int> &A, int l, int r) {
    // l is the zeroth index and r is the last index of the array
    if (l < r) {
        int mid = l + (r - l) /2; //Divide the array into two parts
        mergeSort(A, l, mid); //Call merge sort for the first half
        mergeSort(A, mid + 1, r); //Call merge sort for the second half
        merge(A, l, r, mid); //Merge both the halves
    }
}

// 6 10 9 11 10 15



int main() {

    //Driver code
    vector<int> A = {6,10,9,11,17,15};
    const int size = (int)A.size();
    mergeSort(A, 0, size - 1); //Sorting is done in plkace

    for (auto i: A) cout << i << endl;
}