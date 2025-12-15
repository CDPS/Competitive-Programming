#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll n, m;

ll solve(){

    cin >>  n >> m ;

    ll  l = max(0ll, n-m), r = n + m;

    ll ans = 0;
    for(int i=0;i<32;i++)
        if( ((l&(1ll<<i))!=0) || ((r&(1ll<<i))!=0)  ||  (l/(1ll<<i+1))!=(r/(1ll<<i+1)))
            ans |= (1ll<<i);

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
