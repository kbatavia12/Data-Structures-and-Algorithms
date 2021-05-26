#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

//Not memoized
ll gridTraveler(int m, int n) {
    if (m == 0 || n == 0) return 0;
    else if (m == 1 || n == 1) return 1;
    else return gridTraveler(m-1,n) + gridTraveler(m, n-1);
}



ll gridTravelerMemo(int m, int n,unordered_map<string, ll> &memo) {
    
    string key = to_string(m) + ',' + to_string(n);
    if (memo[key]) return memo[key];
    if (m == 0 || n == 0) return 0;
    if (m == 1 || n == 1) return 1;

    memo[key] = gridTravelerMemo(m - 1,n, memo) + gridTravelerMemo(m, n-1, memo);

    return memo[key];

}

int main() {
    unordered_map<string, ll> memo = {};
    cout << gridTravelerMemo(1,1, memo) << endl;
    cout << gridTravelerMemo(3,4, memo) << endl;
    cout << gridTravelerMemo(5,10, memo) << endl;
    cout << gridTravelerMemo(15,100, memo) << endl;
    cout << gridTravelerMemo(80,120, memo) << endl;
}