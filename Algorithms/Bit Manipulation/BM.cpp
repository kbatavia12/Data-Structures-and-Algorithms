#include <bits/stdc++.h>
using namespace std;


void swap(int &x, int &y) {
    //Swap without the third temporary variable 
    // for x  = 5 (0101)  and y = 3 (0011)
    x = x ^ y; //XOR x with y => x = 0110
    y = x ^ y; //XOR y with new x => y = 0101
    x = x ^ y; //XOR new x with new y => x = 0011

}

void swapMix(int &x, int &y) {
    //Swap the variables using a mix of arithmetic and bitwise operators

    
    x = (x & y) + (x | y); //This is the same as a = a + b
    cout << x << endl;
    y = x + (~y) + 1; //This is the same as b = a - b
    cout << y << endl;

    x = x + (~y) + 1; //This is the same as a = a - b


}

int getMissingNumber(vector<int> nums, int n) {

    int a = 0, b = 0;

    for (int i = 1; i <=n;i++) {
        a ^= i;
    }

    for (auto i:nums) {
        b ^= i;
    }

    return a ^ b;


}


//https://leetcode.com/problems/xor-operation-in-an-array/

int xorOperation(int n, int start) {
    int res = 0;
    int count = 0;

    for (int i = start; count < n;i+=2, count++) {
        res ^= i;
    }

    return res;

}




int hammingDistance(int x, int y) {
    int n = x ^ y;
    int count = 0;

    while(n) {
        if (n & 1) count++;
        n >>= 1;
    }

    return count;

}


vector<int> decode(vector<int>& encoded, int first) {
    vector<int> res(encoded.size() + 1);
    res[0] = first;
    
    for (int i = 0; i < encoded.size(); i++) {
        res[i + 1] = encoded[i] ^ res[i];
    }

    // res.push_back(res[i] ^ encoded[i]);

    return res;


}

int maxAscendingSum(vector<int> nums) {
    int maxi = INT_MIN;
    int sum = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
        sum += nums[i];
        if (nums[i] < nums[i + 1]) {
            // sum += nums[i - 1];
            continue;
        } else {
            maxi = max(sum , maxi);
            sum = 0;
        }

    }

    maxi = max(sum + nums[nums.size() - 1], maxi);

    return maxi;

}



int main() {

    // int a = 5;
    // int b = 3;
    // swap(a,b);
    // cout << a << ' ' << b << endl;
    // swapMix(a, b);
    // cout << a << ' ' << b << endl;;

    // cout << getMissingNumber({1,2,4,5}, 5) << endl;
    // cout << (1 << 5) << endl; 
    
    // 000001 1 *2
    // 000010 2 * 2
    // 000100 4 * 2
    // 001000 8 * 2
    // 010000 16 * 2

    // cout << xorOperation(5,0) << endl;
    // cout << xorOperation(4,3) << endl;
    // cout << xorOperation(1,7) << endl;
    // cout << xorOperation(10,5) << endl;
    
    

    // cout << hammingDistance(3, 1) << endl;
    
    // vector<int> a = {6,2,7,3};
    // vector<int> ans = decode(a, 4);
    // for (auto i:ans) cout << i << " ";

    vector<int> nums = {10,20,30,5,10,50};

    cout << maxAscendingSum(nums) << endl;
    cout << maxAscendingSum({10,20,30,40,50}) << endl;
    cout << maxAscendingSum({12,17,15,13,10,11,12}) << endl;
    cout << maxAscendingSum({100,10,1}) << endl;


    return 0;
}