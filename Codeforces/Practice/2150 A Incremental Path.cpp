#include <bits/stdc++.h>

using namespace std;

int t, n, m, x;

string s;

void solve(){

    cin >> n >> m >> s;

    set<int> st;
    for(int i=0; i < m; i++)
        cin >> x, st.insert(x);

    int curr = 1;
    for(int i = 0; i < n; i++) {
        if(i > 0) {
            if(s[i-1] == 'B')
                while(st.count(curr)) curr++;
        }

        curr++;
        if(s[i] == 'B'){
            while(st.count(curr)) curr++;

        }
        st.insert(curr);
    }

    cout << st.size() << "\n";
    for(auto val : st)
        cout << val << " ";
    cout << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
