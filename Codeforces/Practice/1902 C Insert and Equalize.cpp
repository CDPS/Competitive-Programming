#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
ll a[2000001];

ll solve(){

    cin >> n;

    set<ll> st;
    for(int i=0;i<n;i++)
        cin >> a[i], st.insert(a[i]);
    sort(a, a + n);

    if(n == 1 ) return 1;

    ll x = a[n-1] - a[0];
    for(int i=1;i<n-1;i++)
        x = __gcd(x, a[n-1]-a[i]);

    for(int i=1;i<=n;i++)
        if( !st.count(a[n-1]  - x*i) ){
            a[n] = a[n-1]  - x*i;
            break;
        }

    ll ans  = 0;
    for(int i=0;i<=n;i++)
        ans += (a[n-1] - a[i])/x;

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";
}
