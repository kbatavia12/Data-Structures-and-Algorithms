#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

//Not memoized
bool canSum(int target, vector<ll> nums) {
    if (target == 0) return true;
    if (target < 0) return false;
    for (int i = 0; i < nums.size();i++) {
        int remainder = target - nums[i];
        if (canSum(remainder, nums)) {
            return true;
        }
    }
    return false;
}

//Memoized
bool canSumMemo(int target, vector<ll> nums, unordered_map<ll, bool> &lookupTable) {
    if (lookupTable.find(target) != lookupTable.end()) return lookupTable[target];
    if (target == 0) return true;
    if (target < 0) return false;

    bool ans = false;
    for (auto i: nums) {
        ll remainder = target  - i;
        ans = ans || canSumMemo(remainder, nums, lookupTable);
        if (ans) {
            lookupTable.emplace(target, true);
            return true;
        }
    } 
    lookupTable.emplace(target, false);
    return false;

}


int main() {

    vector<ll> nums = {7,14};
    unordered_map<ll, bool> lookupTable = {};
    cout << canSumMemo(300, nums, lookupTable) << endl;

    return 0;
}