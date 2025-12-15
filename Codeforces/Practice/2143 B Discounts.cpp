#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n, m;
ll   a[200000], b[200000];


ll solve(){

    cin >> n >> m;

    ll ans = 0;
    for(int i=0;i<n;i++) cin >> a[i], ans+=a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    sort(a, a+n);
    sort(b, b+m);

    for(int i=0, curr=n -1;i<m;i++){
        curr-=b[i]-1;
        if(curr < 0) break;
        ans-=a[curr--];
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
