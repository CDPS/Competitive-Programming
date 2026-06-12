#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int t = 1, n, m;

string a[100];

int solve(){

    cin >> n >> m;

    for(int i=0;i<n;i++) cin >> a[i];

    int ans = 1;
    for(int j=0; j < m; j++){
        set<char> st;
        for(int i=0; i < n; i++)
            st.insert(a[i][j]);
        ans = (ans * st.size())%mod;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        cout << solve() << "\n";

    return 0;
}
