#include <bits/stdc++.h>
using namespace std;


//https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/
int minimumAbsoluteDifference(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int min = INT_MAX;
    
    for (int i = 0; i < arr.size();i++) {
        if (abs(arr[i] - arr[i+1]) < min) {
            min = abs(arr[i] - arr[i+1]);
        }
    }
    return min;
       
}


//https://www.hackerrank.com/challenges/grid-challenge/problem
//https://www.hackerrank.com/challenges/luck-balance/problem

int main () {
    
    return 0;
}