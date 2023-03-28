#include <bits/stdc++.h>

using namespace std;

bool isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='(' || x==')')
        return 0;
    return 1;
}

int outPrecedence(char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 3;
    else if(x=='^')
        return 6;
    else if(x=='(')
        return 7;
    else if(x==')')
        return 0;
    return -1;
}

int inPrecedence(char x)
{
    if(x=='+' || x=='-')
        return 2;
    else if(x=='*' || x=='/')
        return 4;
    else if(x=='^')
        return 5;
    else if(x=='(')
        return 0;
    return -1;
}

string InfixtoPostfix(string infix)
{
    string postfix = "";
    stack<char> st;
    int i=0;
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix += infix[i++];
        else
        {
            if(st.empty() || outPrecedence(infix[i])>inPrecedence(st.top()))
            {
                st.push(infix[i++]);
            }
            else if(outPrecedence(infix[i])==inPrecedence(st.top()))
            {
                st.pop();
            }
            else
            {
                postfix += st.top();
                st.pop();
            }
        }
    }
    while(!st.empty() && st.top()!=')')
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int Evaluate(string postfix)
{
    stack<int> st;
    int x1,x2,r,i=0;
    while (postfix[i]!='\0')
    {
        if(isOperand(postfix[i]))
            st.push(postfix[i++]-'0');
        else
        {
            x2 = st.top();
            st.pop();
            x1 = st.top();
            st.pop();
            switch (postfix[i++])
            {
            case '+':
                r = x1+x2;
                st.push(r);
                break;
            
            case '-':
                r = x1-x2;
                st.push(r);
                break;

            case '*':
                r = x1*x2;
                st.push(r);
                break;

            case '/':
                r = x1/x2;
                st.push(r);
                break;

            default:
                cout << "Invalid Operator!" << endl;
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string exp = "3*5+6/2-4";
    string res = InfixtoPostfix(exp);
    cout << res << endl;
    cout << Evaluate(res) << endl;
    return 0;
}