#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
ll a[200000];

ll solve(){

    cin >> n;

    ll ans = 0;
    for(int i=0;i<n;i++)
        cin >> a[i], ans = (i%2)? ans-a[i]: ans + a[i];

    ll maxi = -4e18, init = ans;
    for(int i=1;i<n;i++){
        ll curr = 2*a[i]-i;
        if(i%2==0)
            ans  = max(ans , init + maxi - curr);
        else
            maxi = max(maxi, curr);
    }

    ll mini =  4e18;
    for(int i=0;i<n;i++){
        ll curr = 2*a[i]+i;
        if(i%2)
            ans = max(ans , init + curr - mini);
        else
            mini = min(mini, curr);
    }

    return (n%2)? max(ans, init + n-1) :  max(ans, init + n-2);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
