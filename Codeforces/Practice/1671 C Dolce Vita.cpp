#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, t;
ll   a[200000], x;
ll pfx[200001];

ll solve(){

    cin  >> n >> x;
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a, a + n);

    for(int i=0;i<n;i++)
        pfx[i+1]= a[i] + pfx[i];

    ll ans = 0;
    for(int i=1;i<=n;i++){
        if(pfx[i] > x ) break;
        ll days = ((x-pfx[i])/i) + 1;
        ans += days;
    }
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
