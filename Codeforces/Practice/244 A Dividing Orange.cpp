#include <bits/stdc++.h>

using namespace std;

int n, k;

void solve(){

    cin >> n >> k;
    vector<vector<int> > a( k, vector<int> (n));

    set<int> st;
    for(int i=0, curr = 1; i < k ;i++)
        for(int j = 0; j < n ; j ++)
            st.insert(curr++);

    for(int i=0;i<k;i++)
        cin >> a[i][0] , st.erase(a[i][0] );

    for(int i=0; i < k ;i++)
        for(int j = 1; j < n ; j ++)
            a[i][j] = *st.begin(), st.erase(a[i][j] );

    for(int i=0; i < k ;i++)
        for(int j = 0; j < n ; j ++)
            cout << a[i][j] << " \n"[j==n-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    solve();

    return 0;
}
