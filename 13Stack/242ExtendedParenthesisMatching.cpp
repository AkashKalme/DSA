#include <bits/stdc++.h>

using namespace std;

bool isBalanced(char *e)
{
    map<char, char> mp;
    mp['}'] = '{';
    mp[']'] = '[';
    mp[')'] = '(';
    
    map<char, char> :: iterator itr;

    stack<char> st;

    for(int i=0; i<strlen(e); i++)
    {
        if(e[i]=='{' || e[i]=='[' || e[i]=='(')
        {
            st.push(e[i]);
        }
        else if(e[i]=='}' || e[i]==']' || e[i]==')')
        {
            if(st.empty())
                return false;
            char temp = st.top();
            itr = mp.find(e[i]);
            if(temp == itr->second)
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main()
{
    char exp[] = "(]";
    cout << isBalanced(exp) << endl;
    return 0;
}