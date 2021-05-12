#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &A, int n) {
    int data;
    for (int i = 1; i < n;i++) {
        data = A[i];
        int j = i - 1;


        while(j >= 0 && A[j] > data) {
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = data;
    }
}

void printList(vector<int> A) {
    int i = 0;
    while(i < A.size()) {
        cout<< A[i] << " ";
        ++i;
    }
    cout << endl;
}


//https://www.hackerrank.com/challenges/insertionsort1/problem
void insertionSort1(int n, vector<int> &arr) {
    int data = arr[n-1];
    int i = n - 1;
    int j = i - 1;
    
    while(j >= 0 && arr[j] > data) {
        arr[j + 1] = arr[j];
        j--;
    }
        // printList(arr);
    
    arr[j+1] = data;
    printList(arr);
}

//https://www.hackerrank.com/challenges/insertionsort2/problem
void insertionSort2(int n, vector<int> arr) {
    int data;

    for (int i = 1; i < n;i++) {
        data = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > data) {
            arr[j+1] = arr[j];
            j--;
            printList(arr);
        }

        arr[j+1] = data;
        printList(arr);

    }

}

//https://www.hackerrank.com/challenges/runningtime/problem
int runningTime(vector<int> arr) {
    int data, count = 0;
    
    for (int i = 1; i < arr.size();i++) {
        data = arr[i];
        int j = i - 1;
        
        while(j>=0 && arr[j] > data) {
            count++;
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = data;
        
        
    }
        return count;
    
}



int main() {

    vector<int> A = {2,1,3,1,2};

    // printList(A);

    // insertionSort2(5, A);

    cout << runningTime(A) << endl;

    // printList(A);

    return 0;
}