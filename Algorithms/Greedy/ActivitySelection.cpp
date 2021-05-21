#include <bits/stdc++.h>
using namespace std;


int numberOfActivities(vector<int> start, vector<int> finish, int n) {

    int j = 0;
    vector<int> resIndex;
    resIndex.push_back(j);

    for (int i = 1; i < n;i++) {
        if (start[i] >= finish[j]) {
            resIndex.push_back(i);
            j = i;
        } else {
            continue;
        }
    }

    // for (auto i: resIndex) cout << i << " ";
    return resIndex.size();

}


int main() {

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};



    cout << numberOfActivities(start, finish, 6);

    return 0;   
}