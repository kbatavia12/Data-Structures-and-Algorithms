#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> res;

//Not memoized
bool howSum(int target, vector<ll> nums) {
    if (target == 0) return true;
    if (target < 0) return false;

    for (auto i: nums) {
        ll remainder = target - i;
        if (howSum(remainder, nums)) {
            res.push_back(i);
            return true;
        }
    }

    return false;
} 

//Memoized
unordered_map<int, ll> memo = {};
vector<ll> ans;
bool howSumMemo(int target, vector<ll> nums) {
    if (memo.find(target) != memo.end()) return memo[target];
    if (target == 0) return true;
    if (target < 0) return false;

    for (auto i:nums) {
        ll remainder = target - i;
        if (howSumMemo(remainder, nums)) {
            ans.push_back(i);
            memo.emplace(target, true);
            return true;
        }
    }

    memo.emplace(target, false);
    return false;

}



int main() {
    vector<ll> nums = {7,14};
    // if (howSum(7, nums)) {
    //     for (auto i: res) {
    //         cout << i << " ";
    //     }
    // }

    if (howSumMemo(300, nums)) {
        for (auto i: ans) {
            cout << i << " ";
        }
    } else {
        cout << "Not found" << endl;
    }

    return 0;   
}