#include <bits/stdc++.h>
using namespace std;

long long gridTravelerTab(int m, int n) {
    vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));

    dp[1][1] = 1;
    for(int i=0; i<=m; ++i) {
        for(int j=0; j<=n; ++j) {
            int current = dp[i][j];
            if(i+1 <= m) dp[i+1][j] += current;
            if(j+1 <= n) dp[i][j+1] += current;
        }
    }

    return dp[m][n];
}

int main() {

    cout << gridTravelerTab(50,50) << endl;

}