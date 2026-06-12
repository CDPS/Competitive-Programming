#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

bool solve(){

    cin >> n >> s;

    stack<char> st;
    for(int i=0;i<n;i++){
        if(st.empty())
            st.push(s[i]);
        else if(st.top() == s[i])
            st.pop();
        else
            st.push(s[i]);
    }

    return st.empty();
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";

    return 0;
}
