#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n; ll k;

ll a[100000];

void solve(){

    cin >> n >> k;

    for(int i=0;i<n;i++) cin >> a[i];

    sort(a, a+ n);

    int ans = 0, num = 0;
    ll sum = 0;
    for(int j=0, i= 0;j<n;j++){

        sum+=a[j];

        while( a[j]*(j-i+1ll) - sum > k )
            sum-=a[i], i++;

        if(  j-i+1 > ans  )
            ans = j-i+1, num = a[j];
    }

    cout << ans << " " << num  << "\n";
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
