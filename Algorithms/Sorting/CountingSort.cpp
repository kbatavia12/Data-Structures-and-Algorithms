#include <bits/stdc++.h>
using namespace std;

const int RANGE = 8;

void countSort(vector<int> A) {
    vector<int> countFrequency(RANGE); //Vector to store the counts
    vector<int> sortedList(7); //Vector to store the output sorted array

    for (int i = 0; i < A.size();++i) {
        ++countFrequency[A[i]]; //Store the counts of each element (hashing)
    }

    for (int i = 1; i <= RANGE - 1;++i) {
        countFrequency[i] += countFrequency[i-1]; //Each element in the frequecny array is the sum of itself and the previous element
    }

    for (int i = 0; i < A.size();++i) {
       sortedList[countFrequency[A[i]] - 1] = A[i]; //Store the element at A[i] in the value: [countFrequency[A[i]] - 1]th position
       countFrequency[A[i]]--; //Decrement the value in the countFrequency
    }

    for (auto i: sortedList) cout << i << " "; //Print out the elements

}

int main() {
    // vector<int> arr = {1,4,1,2,7,5,2};
    // countSort(arr);
    

    int T;
    cin >> T;
    
    vector<int> inp(T);
    vector<int> countFrequency(100);
    vector<int> sumList(100);
    int sum = 0;
    string data;

    for (int i = 0; i < T;i++) {
        cin >> inp[i]; 
        countFrequency[inp[i]]++;  
        cin >> data;
    }

    for (int i = 0; i < countFrequency.size();i++) {
        sum+=countFrequency[i];
        sumList[i] = sum;
    }

    for (auto i: sumList) {
        cout << i << " ";
    }



    return 0;

}