#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

ll  a[200000];
ll  b[200000];
ll dp[200001];
ll acc[200001];

int main(){

    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];

    ll pos = 0, neg = 0;
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(a[i]<0)acc[++neg] = pos, ans+=((pos*(pos+1))/2ll), pos =0;
        else pos++;
        b[i] = neg;
    }
    ans+=((pos*(pos+1))/2ll);

    acc[0] = -1;
    for(int i=1;i<=neg;i++)
        dp[i] = acc[i-1] + 1 + dp[i-1];

    for(int i=0;i<n;i++)
       if(b[i]%2==0) ans+= dp[ b[i] ];
       else {
            if(b[i]>=3)
                ans += dp[ b[i]-2 ];
       }

    cout << ((n*(n+1))/2)-ans << " " << ans << "\n";

    return 0;
}

