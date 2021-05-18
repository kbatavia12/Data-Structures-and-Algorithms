#include <bits/stdc++.h>
using namespace std;

//https://www.hackerrank.com/challenges/encryption/problem
string encryption(string s)
{
    int l = s.length();
    int rows = floor(sqrt(l));
    int columns = rows + 1;

    if ((rows * columns) < l)
    {
        rows++;
    }

    if ((rows * rows) == l)
    {
        columns = rows;
    }

    string result = "";
    cout << l << endl;
    for (int i = 0; i < columns; i++)
    {
        for (int j = i; j < l; j += columns)
        {
            result += s[j];
        }
        result += " ";
    }

    return result;
}

//https://www.hackerrank.com/challenges/an-interesting-game-1/problem
string gamingArray(vector<int> arr)
{
    int count = 0;
    int max = arr[0];
    for (auto i : arr)
    {
        if (i > max)
        {
            max = i;
            count++;
        }
    }

    return count % 2 == 0 ? "ANDY" : "BOB";
}

//https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
    stack<int> s;
    vector<int> results;
    for (int i = 0; i < ranked.size(); i++)
    {
        if (ranked[i] != s.top())
        {
            s.push(ranked[i]);
        }
    }

    int i = 0;

    for (int j = 0; j < player.size(); j++)
    {
        while (!s.empty() && player[i] >= s.top())
        {
            s.pop();
        }

        i++;
        results.push_back(s.size() + 1);
    }

    return results;
}

//https://www.hackerrank.com/challenges/weighted-uniform-string/problem

vector<string> weightedUniformStrings(string s, vector<int> queries)
{
    vector<string> result;
    vector<int> values;
    int count = 1;
    int currValue = s[0] - 96;
    values.push_back(s[0] - 96);

    for (int i = 1; i < s.size(); i++)
    {
        char letter = s[i];
        if ((s[i] - 96) != currValue)
        {
            count = 1;
            currValue = s[i] - 96;
            values.push_back(currValue * count);
        }
        else
        {
            count++;
            values.push_back(currValue * count);
        }
    }

    for (auto i : queries)
    {
        if (std::find(values.begin(), values.end(), i) != values.end())
        {
            result.push_back("Yes");
        }
        else
        {
            result.push_back("No");
        }
    }

    return result;
}

//https://www.hackerrank.com/challenges/icecream-parlor/problem

vector<int> icecreamParlor(int m, vector<int> arr)
{
    vector<int> hash(10001);
    vector<int> res(2);
    for (int i = 0; i < arr.size(); i++)
    {
        hash[arr[i]]++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (hash[m - arr[i]] >= 1)
        {
            res[0] = (i + 1);
            auto it = find(arr.begin(), arr.end(), m - arr[i]);
            if (it - arr.begin() + 1 == res[0]) {
                res[1] = it - arr.begin() + 2;
            } else {
                res[1] = it - arr.begin() + 1;
            }
            break;
        }
    }
    return res;
}

int main()
{
    // vector<int> a = {100, 100, 50, 40, 40, 20, 10};
    // vector<int> b = {5, 25, 50, 120};
    // climbingLeaderboard(a, b);
    // vector<int> b = {1,3,12,5,9,10};
    // vector<string> ans = weightedUniformStrings("abccddde", b);

    // for (auto i:ans) {
    //     cout << i << " ";
    // }
    // vector<int> b = {2, 2, 4, 3};
    // vector<int> ans = icecreamParlor(4, b);

    // for (auto i : ans)
    // {
    //     cout << i << " ";
    // }

    int n = 100;
    long long int z = 1;

    for (int i = 1; i < 61;i++) {
        z*=i;
    }

    cout << z;



    return 0;
}