#include <bits/stdc++.h>

using namespace std;

const char l = 'l';
const char r = 'r';
int t = 1, n;

string s;

void solve(){

    cin >> s; n = s.size();

    stack<int> st; queue<int> q;
    for(int i=0;i < n;i++){
        if(s[i] == l ) st.push(i+1);
        if(s[i] == r ) q.push(i+1);
    }

    while(!q.empty())
        cout << q.front() << "\n", q.pop();
    while(!st.empty())
        cout << st.top() << "\n", st.pop();
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}

