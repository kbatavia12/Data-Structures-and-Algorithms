#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> res;
    int max = candies[0];
    for (int i = 1; i < candies.size();i++) {
        if (candies[i] > max) {
            max = candies[i];
        }
    }


    for (int i = 0; i < candies.size();i++) {
        if (candies[i] + extraCandies >= max) {
            res.push_back(true);
        } else {
            res.push_back(false);
        }
    }

    return res;

}


//https://leetcode.com/problems/find-smallest-letter-greater-than-target/
char nextGreatestLetter(vector<char>& letters, char target) {
    char ans;
    int flag = 0;
    for (int i = 0; i < letters.size();i++) {
        int c = letters[i];

        if (c > target) {
            ans = c;
            flag = 1;
            break;
        }

    }

    if (target == 'z' || target == letters[letters.size() - 1] || !flag) return letters[0];

    return ans;

} 

//https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
vector<int> replaceElements(vector<int>& arr) {
    
    if (arr.size() == 1) {
        return {-1};
    }
    
    vector<int> res(arr.size());
    int max = arr[arr.size() - 1];
    res[arr.size() - 1] = -1;
    for (int i = arr.size() - 2;i >= 0;i--) {
        res[i] = max;
        if (arr[i] > max) {
            max = arr[i];
        }
    } 

    return res;

}

//https://leetcode.com/problems/assign-cookies/
int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, count = 0;

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                count++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return count;
}


//https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/

vector<int> minSubsequence(vector<int>& nums) {
        int rest = 0;
        for(int i : nums) rest += i;
        sort(nums.begin(),nums.end(),greater<int>());
        int curr = 0;
        vector<int> res;
        for(int i : nums) 
        {
            curr += i;
            rest -= i;
            res.push_back(i);
            if(curr>rest) break;
        }
        return res;
    }




int main() {
    // vector<int> candies = {12,1,12};
    // vector<bool> ans = kidsWithCandies(candies, 10);
    // for (auto i: ans) cout << i << " ";

    // vector<char> letters = {'c', 'f', 'j'};
    // char target = 'a';
    // cout << nextGreatestLetter(letters, target);

    // vector<int> arr = {400};
    // vector<int> ans = replaceElements(arr);
    // for (auto i: ans) cout << i << " ";

    // vector<int> g = {1,2,3};
    // vector<int> s = {1,1};
    // cout << findContentChildren(g,s);

    // vector<int> nums = {4,3,10,9,8};
    // vector<int> nums = {4,4,7,6,7};
    // vector<int> ans = minSubsequence(nums);
    // for (auto i: ans) cout << i << " ";


    return 0;
}