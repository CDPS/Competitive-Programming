#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t = 1, n;
ll a[100001];

ll solve(){

    cin >> n;
    for(int i = 0; i <n; i++) cin >> a[i];
    sort(a, a + n );

    vector<ll> v;
    for(int i=n-1;i >= 1; i--)
        if(a[i] -a[i-1] <=1)
            v.push_back( a[i-1] ), i--;

    ll ans = 0;
    for(int i=0;  i + 1 < v.size(); i+=2)
        ans+= v[i]*v[i+1];

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
