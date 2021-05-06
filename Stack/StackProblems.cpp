#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/valid-parentheses/
bool isValid(string s)
{
    stack<char> stack; //Stack to store the opening chars
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            stack.push(s[i]); //Push if we encounter an opening pair
        else if (!stack.empty())
        {
            if (s[i] == ')' && stack.top() == '(')
                stack.pop(); //If we encounter a ')' and the top is its complement, pop it
            else if (s[i] == '}' && stack.top() == '{')
                stack.pop(); //If we encounter a '}' and the top is its complement, pop it
            else if (s[i] == ']' && stack.top() == '[')
                stack.pop(); //If we encounter a ']' and the top is its complement, pop it
            else
                return false; //If the top is a complement to a different character, the string is not valid
        }
        else
            return false; //If we encounter anything else, the string is not valid
    }

    return stack.empty(); //At the end, if the stack is empty, the string is valid, else it isn't
}

//Function to check operator precedence
int opPrecedence(char symbol)
{
    if (symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
    stack<char> st; //Stack to push the operators
    string result;  //The resulting postfix string

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c; //If the character is an operand, put it into the result
        else if (c == '(')
            st.push(c); //If we encounter an opening paranthesis, push it
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                char popper = st.top(); //If we encounter a closing paranthesis, Pop each and every operator from the
                st.pop();               //stack, until an opening paranthesis is at the top
                result += popper;
            }
            st.pop(); //Discard the opening paranthesis
        }
        else
        {
            while (!st.empty() && opPrecedence(s[i]) <= opPrecedence(st.top()))
            {
                char popper = st.top(); //If the current operator is below in the precedence table than the one on the top of the stack, pop the stack
                st.pop();
                result += popper; //Add the smaller precedence operator in the result
            }
            st.push(c); //Push the lower operator in the stack
        }
    }

    //Empty the stack and add the remaining elements
    while (!st.empty())
    {
        char popper = st.top();
        st.pop();
        result += popper;
    }

    return result;
}

//https://leetcode.com/problems/design-a-stack-with-increment-operation/
class CustomStack 
{
public:
    int top = 0;
    int size = 0;
    int a[5000];
    
    CustomStack(int maxSize) 
    {
        size = maxSize;
    }
    
    void push(int x) 
    {
        if ( top < size ) 
            a[top++] = x;        
    }
    
    int pop() 
    {
        if ( top > 0 )
            return a[--top]; 
        return -1;
    }
    
    void increment(int k, int val) 
    {
        for ( int i=0; i<min(k,top); i++) 
            a[i] += val;
    }
};

int main()
{
    // string exp = "a+(b*c)^e*d";

    // cout << infixToPostfix(exp) << endl;

    CustomStack* obj = new CustomStack(3);
    obj->push(1);
    obj->push(2);
    obj->push(3);
    
    cout << obj->pop() << endl;

    // cout << obj->pop() << endl;



    return 0;
}