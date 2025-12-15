#include <bits/stdc++.h>

using namespace std;

int t, n, m, q, x;

int a[200000];

bool solve(){

    cin >> n >> m >> q;

    for(int i=0;i<n;i++) cin >> a[i];

    set<int> st;
    vector<int> first;

    for(int i=0;i<m;i++) {
        cin >> x;
        if(!st.count(x))
            first.push_back(x);
        st.insert(x);
    }

    for(int i=0;i<first.size();i++)
        if(first[i] != a[i])
            return false;

    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << ( solve()? "YA" : "TIDAK" ) << "\n";

    return 0;
}


