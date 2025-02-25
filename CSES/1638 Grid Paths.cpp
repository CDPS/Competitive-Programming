#include <bits/stdc++.h>

using namespace std;

int const m = 1e9 + 7;
char  a[1001][1001];
int dp[1001][1001];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;

    for(int i=0;i<=n;i++)
        a[0][i] = a[i][0] = '*';

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> a[i][j];

    if(a[1][1] != '*') dp[1][1] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]!='*'){
                if(a[i][j-1]!='*') dp[i][j] = ( dp[i][j]+ dp[i][j-1] )%m;
                if(a[i-1][j]!='*') dp[i][j] = ( dp[i][j]+ dp[i-1][j] )%m;
            }
        }
    }


    cout << dp[n][n] << "\n";

    return 0;
}
