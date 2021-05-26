#include <bits/stdc++.h>
using namespace std;


unsigned long long int fibTab(int n) {
    vector<unsigned long long int> tab(n+1,0);
    if (n <= 2) return 1;
    tab[0] = 0;
    tab[1] = 1;

    for (int i = 2; i <= n;i++) {
        tab[i] = tab[i - 1] + tab[i - 2];
    }

    return tab[n];
}


int main() {
    cout << fibTab(10) << endl;
}