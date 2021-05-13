#include <bits/stdc++.h>
using namespace std;

//https://www.hackerrank.com/challenges/encryption/problem
string encryption(string s) {
    int l = s.length();
    int rows = floor(sqrt(l));
    int columns = rows + 1;

    if ((rows*columns) < l) {
        rows++;
    }

    if ((rows*rows) == l) {
        columns = rows;
    }
  
    string result = "";
    cout << l << endl;
    for (int i = 0; i < columns;i++) {
        for (int j = i; j < l;j+=columns) {
            result += s[j];
        }
        result+= " ";
    }
    
    return result;
        
}


int main () {
    cout << encryption("haveaniceday") << endl; 
    return 0;
}