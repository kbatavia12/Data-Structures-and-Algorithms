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

int main() {
    vector<int> A = {1,2,3,4,5};

    cout << linearSearch(3, A);
}