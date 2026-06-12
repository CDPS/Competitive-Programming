#include <bits/stdc++.h>

using namespace std;

int t, m, k, a1, ak;

int solve(){

    cin >> m >> k >> a1 >> ak;

    int mod = m % k ;

    int ans = 0;
    if( a1 > mod )
        a1-= mod;
    else
        ans += mod - a1, a1 = 0;

    int blocks_curr =  ak + (a1/k);
    int blocks_needed = m/k;

    if(blocks_needed > blocks_curr)
        ans+= blocks_needed - blocks_curr;

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n" ;

    return 0;
}
