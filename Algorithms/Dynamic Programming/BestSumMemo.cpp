#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> res;


bool bestSum(int target, vector<ll> nums) {
    if (target == 0) return true;
    if (target < 0) return false;
    vector<ll> shortestCombination = {};

    for (auto i:nums) {
        ll remainder = target - i;
        bool check = bestSum(remainder, nums);

        if (check) {
            res.push_back(i);
            if (res.size() < shortestCombination.size() || shortestCombination.empty()) {
                shortestCombination = res;
            }
        }
    }

    if (!shortestCombination.empty()) res = shortestCombination;

    


}

int main() {
    bool ans = bestSum(7, {5,3,4,7});
    if (ans) {
        for (auto i: res) {
            cout << i << " ";
        }
    } else {
        cout << "Not found" << endl;
    }
}
