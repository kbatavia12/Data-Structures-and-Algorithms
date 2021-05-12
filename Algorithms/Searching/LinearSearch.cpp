#include <bits/stdc++.h>
using namespace std;

//I can't explain this

int linearSearch(int val, vector<int> A) {
    for (int i = 0; i < A.size();i++) {
        if (A[i] == val) {
            return i;
        }
    }

    return -1;
}

int linearSearchRecursive(int val, int arr[]) {
    //The main idea is to consider the array from each subsequent element
    if (val == arr[0]) {
        return 0; //Each element gets to become the zeroth element of the array
    } else {
        return linearSearchRecursive(val, arr+1) + 1;  //The total number of elements traversed get added up during the return time of the function
    }
}


int main() {
    int A[5] = {3,2,4,5,1};

    cout << linearSearchRecursive(5, A);
}