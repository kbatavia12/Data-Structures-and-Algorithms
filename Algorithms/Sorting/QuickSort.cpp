#include <bits/stdc++.h>
using namespace std;



//** This implementation of quickSort takes O(n^2) time, here's why
//The callstack size of the recursive function is N and each element is touched N times, therefore the size is **O(n ^ 2)**

vector<int> quickSort(vector<int> arr) {
    if (arr.empty()) return {}; //Base case 1
    if (arr.size() == 1) return arr; //Base case 2
    
    int pivot = arr[0]; //Take the first element of the array as the pivot

    vector<int> lessThan, greaterThan; //Arrays to hold the elements smaller than pivot and greater than pivot


    //Fill the lessThan and greaterThan arrays (Assuming there are no duplicates in the original array)
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < pivot) lessThan.push_back(arr[i]);
        else if (arr[i] > pivot) greaterThan.push_back(arr[i]);
    }

    lessThan = quickSort(lessThan); //Apply quicksort on lessthan
    greaterThan = quickSort(greaterThan); //Apply quicksort on greaterthan


    //The commented approach would be with extra space for the result array
    // vector<int> res;
    // for(auto i:lessThan) res.push_back(i);
    // res.push_back(pivot);
    // for(auto i:greaterThan) res.push_back(i);


    //Modify the original array ===> Fill the original array with lesserthan elements
    for (int i = 0; i < lessThan.size(); i++) {
        arr[i] = lessThan[i];
    }

    //Push the pivot after the lesserthan elements
    arr[lessThan.size()] = pivot;

    //Modify the original array ===> Fill the original array with greaterthan elements
    for(int i = 0; i < greaterThan.size(); i++) {
        arr[i + lessThan.size() + 1] = greaterThan[i]; 
    }
    
    return arr;

}


//** This implementation of quickSort runs in O(nlogn) average time, here's why
//The callstack size is actually N/2, hence the n* logn complexity
//This is the same implementation of quickSort as above, just the pivot is the middle element of the array
vector<int> betterQuickSort(vector<int> arr) {
    const int n = arr.size();
    if (arr.empty()) return {};
    if (n == 1) return arr;

    int pivot = arr[n / 2];

    vector<int> lessThan, greaterThan;

    for (int i = 0; i < n; i++) {
        if (i != n/2) {
            if (arr[i] < pivot) lessThan.push_back(arr[i]);
            else if (arr[i] > pivot) greaterThan.push_back(arr[i]);
        } else continue;
    }

    lessThan = quickSort(lessThan);
    greaterThan = quickSort(greaterThan);


    for (int i = 0; i < lessThan.size(); i++) {
        arr[i] = lessThan[i];
    }

    arr[lessThan.size()] = pivot;

    for(int i = 0; i < greaterThan.size(); i++) {
        arr[i + lessThan.size() + 1] = greaterThan[i]; 
    }

    return arr;

    
}
 


int main() {

    vector<int> arr = {10, 7, 8, 9, 1, 5};
    vector<int> ans = betterQuickSort(arr);

    for (auto i:ans) cout << i << " ";


    return 0;
}