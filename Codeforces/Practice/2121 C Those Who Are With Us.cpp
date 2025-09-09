#include <bits/stdc++.h>

using namespace std;

int solve(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int> (m));
    vector<int> row(n, 0);
    vector<int> col(m, 0);

    int maxi = -1e9;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j], maxi = max(maxi, a[i][j]);

    int total  = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
             row[i] += a[i][j] == maxi, col[j] += a[i][j] == maxi, total += a[i][j]== maxi;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(row[i] + col[j] - (a[i][j]==maxi) == total)
                return maxi-1;

    return maxi;
}


int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        cout << solve() << "\n";

    return 0;
}
