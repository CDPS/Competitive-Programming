#include <bits/stdc++.h>

using namespace std;

long memo[4][101][101][101];
long mod = 1000000007;


long dp(int a, int b, int c, int last){

    if (memo[last][a][b][c] != -1)  return memo[last][a][b][c];
    if (a < 0 || b < 0  || c < 0)   return 0;
    if (a == 0 && b == 0 && c == 0) return 1;

    int ans = 0;
    if(last == 1) ans = (dp(a, b-1, c,2)%mod + dp(a, b, c-1,3)%mod)%mod;
    if(last == 2) ans = (dp(a-1, b, c,1)%mod + dp(a, b, c-1,3)%mod)%mod;
    if(last == 3) ans = (dp(a-1, b, c,1)%mod + dp(a, b-1, c,2)%mod)%mod;

    return memo[last][a][b][c] = ans;
}

int main(){

    int a,b,c;
    cin >> a >> b >> c;

    for(int i=0;i<=3;i++)
        for(int j=0;j<=a;j++)
            for(int k=0;k<=b;k++)
                for(int l=0;l<=c;l++)
                    memo[i][j][k][l] = -1;

    long ans = (dp(a-1, b,c,1)%mod +
                dp(a, b-1,c,2)%mod +
                dp(a, b,c-1,3)%mod)%mod ;

    cout << ans << "\n";
    return 0;
}

