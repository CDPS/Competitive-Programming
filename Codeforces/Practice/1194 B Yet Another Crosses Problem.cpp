#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n, m;

int solve(){

    cin >> n >> m;

    vector<string> g(n);
    for(int i=0;i<n;i++) cin >> g[i];

    vector<int> row(n, 0), col(m, 0);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
                col[j]+= g[i][j]=='*', row[i]+= g[i][j]=='*';

     int ans = 1e9;
     for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            ans = min(ans, (m-row[i]) +  (n-(g[i][j]=='.')-col[j]));

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--)
        cout << solve()<< "\n";
    return 0;
}
