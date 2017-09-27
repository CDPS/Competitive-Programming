#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;   string s;
    cin >> t;  cin.ignore();

    while(t--){

        getline(cin,s);

        stack<char> st;
        bool f=1;

        for(int i=0;i<s.size() && f;i++){
            if(s[i]=='[' || s[i]=='(')
                st.push(s[i]);

            if(s[i]==']'){
                if(!st.empty() && st.top()=='[')
                    st.pop();
                else
                    f=0;
            }

             if(s[i]==')'){
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else
                    f=0;
            }
        }

        if(f && st.empty()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
