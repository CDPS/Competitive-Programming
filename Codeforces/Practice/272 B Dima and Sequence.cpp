#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll a[100000];

ll f(ll x){
    if(x == 0) return 0;
    if( x%2==0 )
        return f(x/2);
    return 1 + f(x/2);
}

ll solve(){

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    map<ll, int> mp;
    ll ans = 0;
    for(int i=0;i<n;i++)
        ans+= mp[ f(a[i]) ]++;
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
