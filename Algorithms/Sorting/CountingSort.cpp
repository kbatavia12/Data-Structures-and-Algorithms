#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &arr) {
    const int n = 11;
    vector<int> countFrequency(n);

    vector<int> res(arr.size());

    for (auto i: arr) {
        countFrequency[i]++;
    }

    for (int i = 1; i < n; i++) {
        countFrequency[i] += countFrequency[i - 1];
    }   

    for (int i = 0; i < arr.size(); i++) {
        res[countFrequency[arr[i]] - 1] = arr[i];
        --countFrequency[arr[i]];
    }

    for (int i = 0; i < arr.size(); i++) arr[i] = res[i];

}


int main() {

    vector<int> a = {4,5,8,1,3,5,7,9,7,10};

    for (auto i: a) cout << i << " ";
    cout << endl;

    countingSort(a);

    for (auto i: a) cout << i << " ";

    return 0;
}