#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;
int n, m;

string a[100];

int pfx[101][101];

int solve(){

    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            pfx[i][j] = (a[i-1][j-1] == 'B') + pfx[i-1][j] + pfx[i][j-1] - pfx[i-1][j-1];

   for(int k=1;k<=min(n, m); k++)
         for(int i=1;i<=n-k+1;i++)
            for(int j=1;j<=m-k+1;j++)
                if(pfx[i + k -1][j + k -1] - pfx[i-1][j + k -1] - pfx[i + k -1][j-1] + pfx[i-1][j-1] ==  pfx[n][m])
                    return (k*k) - pfx[i + k -1][j + k -1] - pfx[i-1][j + k -1] - pfx[i + k -1][j-1] + pfx[i-1][j-1];
   return -1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
