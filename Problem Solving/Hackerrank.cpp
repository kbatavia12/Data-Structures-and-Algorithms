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

int main()
{
    vector<int> a = {100, 100, 50, 40, 40, 20, 10};
    vector<int> b = {5, 25, 50, 120};
    climbingLeaderboard(a, b);
    return 0;
}