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



//https://leetcode.com/problems/calculate-money-in-leetcode-bank/

int totalMoney(int n) {
    if (n <= 7) return (n * (n+1)) / 2;
 
    int i = 1;
    int w = 1;
    int weekOneSum = 28;
    int sum = weekOneSum;

    if (n % 7 == 0) {
        int z = n / 7;
        sum = 0;
        while(z--) {
            sum += weekOneSum;
            weekOneSum+=7;
        } 
        return sum;
    }

    while(++i < n) {
        if (i % 7 == 0) w++;
    }
    int left = n % 7;
    int num = w;

    while(--w > 1) {
        weekOneSum+=7;
        sum+=weekOneSum;
    }


    while(left--) {
        sum += num;
        num++;
    } 

    return sum;

    
}


int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        int ans = 0;
        int i = stones.size() - 1;
        


        while(stones.size() > 1) {
            sort(stones.begin(), stones.end());

            if (stones[i] == stones[i-1]) { 
                // cout << stones[i] << " " << stones[i - 1] << endl;
                stones.erase(stones.end() - 2, stones.end());
                i-=2;
            } else {
                stones[i] -= stones[i-1];
                stones.erase(stones.end() - 2); 
                i--;
            }
        }
        


        return stones[0];
        
}


int getDiagonalSum(vector<vector<int>> m) {
    int n = m.size();
    int i = 0 , j = 0, k = n - 1;
    int d1 = 0, d2 = 0;

    

    while(i < n && j < n && k >= 0) {
        d1+= m[i][j];
        d2+= m[i][k];
        i++; j++;k--;
    }

    return abs(d1 - d2);
    
}


//https://leetcode.com/problems/water-bottles/
int numWaterBottles(int numBottles, int numExchange) {
    if (numBottles == numExchange) return numBottles + 1;
    if (numBottles < numExchange) return numBottles;
    
    int sum = numBottles;
    int bottlesLeft = numBottles;

    while(bottlesLeft >= numExchange) {
        int mod = bottlesLeft % numExchange;
        sum += bottlesLeft / numExchange;
        bottlesLeft /= numExchange;
        bottlesLeft += mod;
    }

    return sum;

}


//https://leetcode.com/problems/lemonade-change/  
bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0, twenty = 0;
    if (bills[0] > 5) return false;

    for (int i = 0; i < bills.size(); i++) {
        // cout << five << " " << ten << " " << twenty << endl;
        
        if (bills[i] == 5) {
            five++;
        } else if (bills[i] == 10) {
            if (five) {ten++; five--;}
            else return false;
        } else {
            if (five >= 3) {
                twenty++;
                five-=3; 
            }  else if (five >=1 && ten >= 1) {
                twenty++;
                five-=1; ten-=1;
            }
            else return false;
        }         
        }

    return true;

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

    // cout << totalMoney(28);

    // vector<int> a = {7,9,13,8,5,4,2};
    // vector<int> b = {2,7,4,1,8,1};
    // vector<int> c = {10,4,2,10};

    // cout << lastStoneWeight(a) << endl;
    // cout << lastStoneWeight(b) << endl;
    // cout << lastStoneWeight(c) << endl;

    // int n;
    // cin >> n;
    // int i = 0, j = 0;
    
    //         int inp = 0;

    // vector<vector<int>> m(n);

    // for (int i = 0; i < n; i++) {
    //     m[i] = vector<int>(n);
    //     for (int j = 0; j < n;j++) {
    //         cin >> inp;
    //         m[i][j] = inp;
    //     }
    // }
    

    // cout << getDiagonalSum(m);

    // cout << numWaterBottles(15,4) << endl;
    // cout << numWaterBottles(9,3) << endl;
    // cout << numWaterBottles(5,5) << endl;
    // cout << numWaterBottles(2,3) << endl;

    vector<int> a = {5,5,5,10,20};
    vector<int> b = {5,5,10};
    vector<int> c = {10,10};
    vector<int> d = {5,5, 10 ,10,20};

    cout << lemonadeChange(a) << endl;
    cout << lemonadeChange(b) << endl;
    cout << lemonadeChange(c) << endl;
    cout << lemonadeChange(d) << endl;

    return 0;
}