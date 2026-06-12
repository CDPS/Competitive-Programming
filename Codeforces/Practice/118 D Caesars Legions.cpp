#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll const mod = 1e8;

int n1, n2, k1, k2;

ll memo[101][101][2];

ll dp(int n, int m, bool prev ){

    if(n == 0 && m == 0) return 1;

    if(memo[n][m][prev] != -1) return memo[n][m][prev];

    ll ans = 0;
    if(prev)
        for(int i=1;i<=min(n, k1);i++)
            ans = ( (ans%mod) + (dp(n-i, m, !prev)%mod) ) %mod;
    else
        for(int i=1;i<=min(m, k2);i++)
            ans = ( (ans%mod) + (dp(n, m-i, !prev)%mod) ) %mod;

    return memo[n][m][prev]  = ans;
}

ll solve(){

    cin >> n1 >> n2 >> k1 >> k2 ;

    memset(memo, -1, sizeof(memo) );

    return (dp(n1, n2, 1) + dp(n1, n2, 0) )%mod;
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
