#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int t, n, x;
int a[31];

ll solve(){

    cin >> n;
    for(int i=0;i<=30;i++) a[i] = 0;

    for(int i=0;i<n;i++){
        cin >> x;
        for(int j=30;j>=0;j--)
            if( (x&(1<<j)) !=0 ){
                a[j]++; break;
            }
    }

    ll ans = 0;
    for(int i=0;i<=30;i++)
        ans += (1ll*a[i]*(a[i]-1))/2ll;

    return ans;
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
