#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define N 100

// not memoized
ll fib(ll n) {
    if (n <= 2) return 1;
    else return fib(n -1) + fib(n -2);
}

//Using memoization
const int NIL = -1;
vector<ll> memo(N, NIL);
ll fibMemo(ll n) {
    if (memo[n] == NIL) {
        if (n <= 1) memo[n] = n;
        else memo[n] = fibMemo(n - 1) + fibMemo(n - 2);
    }
    return memo[n];
}

int main() {
    ll n = 75;
    // unordered_map<ll, ll> memo = {};
    cout << fibMemo(36) << endl;
    cout << fibMemo(60) << endl;
    cout << fibMemo(70) << endl;
    cout << fibMemo(80) << endl;
    cout << fibMemo(90) << endl;
}