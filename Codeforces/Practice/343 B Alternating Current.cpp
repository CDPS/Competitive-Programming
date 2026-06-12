#include <bits/stdc++.h>

using namespace std;

int t = 1, n;
string s;

bool solve(){

    cin >> s;

    n = s.size();

    if(n %2 ) return false;

    stack<char> st;
    for(int i=0; i< n; i++){
        if(st.empty() || st.top() != s[i] )
            st.push(s[i]);
        else
            st.pop();
    }
    return st.empty();
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    while(t--)
        cout << (solve()? "Yes" : "No" ) << "\n";

    return 0;
}
