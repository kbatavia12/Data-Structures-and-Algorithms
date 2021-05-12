#include <bits/stdc++.h>
using namespace std;


//** Binary Search only works with SORTED lists and arrays
//** The algorithm is called binary search because it chops our search constraints in half after each iteration
int binarySearch(int x, vector<int> sortedArray) {
    //The main idea is to divide the array into two parts, the lower and upper half, as the elements are sorted, we will know which part our value lies in

    int low = 0, high = sortedArray.size() - 1; //Low points to the first index, high points to the last index
    int mid = (low + high) / 2; //Mid points to the middle of the array

    while(low <= high) { //While the low pointer is less than or equal to the high pointer
        if (x > sortedArray[mid]) { //If our value is greater than the value at the middle of the array, our value lies in the upper half of the array
            low = mid + 1; //This is the new low
            mid = (low + high) / 2; //This is the new mid, considering our low pointer has changed
        } else if (x < sortedArray[mid]) { //If our value is smaller than the value at the middle of the array, our value lies in the lower half of the array
            high = mid - 1; // This is the new high
            mid = (low + high) / 2; //This is the new mid, considering our low pointer has changed
        } else {
            return mid; //If the values equals the value at the middle, the mid is the location of the value in the array
        }
    }

    return -1;



}

int main() {
    vector<int> A = {1,2,3,4,5};

    cout << binarySearch(3, A);
}