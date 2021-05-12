#include <bits/stdc++.h>
using namespace std;

//Check if array is sorted using recursion

bool checkSortedArray(int arr[], int n) {
    if (n==1) return true;
    bool oneToEnd = checkSortedArray(arr + 1, n - 1);

    return (arr[0] < arr[i] && oneToEnd);

}


int main() {

}