#include <bits/stdc++.h>
using namespace std;

//Not memoized
bool canConstruct(string target, vector<string> wordBank) {
    if (target == "") return true;
    
    for (auto word: wordBank) {
        if (target.rfind(word,0) == 0) {
            string suffix = target.substr(word.length());
            if (canConstruct(suffix, wordBank)) return true;
        }
    }

    return false;
}

//Memoized
unordered_map<string, bool> memo = {};
bool canConstructMemo(string target, vector<string> wordBank) {
    if (target.size() == 0) return true;
    if (memo.find(target) != memo.end()) return memo[target];

    for (auto word: wordBank) {
        if (target.find(word) == 0) {
            string suffix = target;
            suffix.erase(0, word.size());
            memo[target] = canConstructMemo(suffix, wordBank);
            return memo[target];
        }
    }
    memo[target] = false;
    return false;
}


int main() {

    cout << canConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}) << endl;
    cout << canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl;

    // unordered_map<string, bool> &memo
    cout << canConstructMemo("eeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeeeeeeee", "eeeeeeeeeee", "eeee"}) << endl;
}