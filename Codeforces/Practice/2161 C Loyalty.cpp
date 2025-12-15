#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
ll x;

ll a[100000];

void solve(){

    cin >> n >> x;
    for(int i=0;i<n;i++) cin >> a[i];

    sort(a, a + n);


    ll acc= 0, ans = 0;
    vector<int> v;

    int i = 0, j = n-1;
    while(i <= j ){
        if( (a[j] + acc)/x  >  acc/x )
            ans+= a[j], acc+= a[j], v.push_back(a[j]), j-- ;
        else
            acc+=a[i], v.push_back(a[i]), i++;
    }

    cout << ans << "\n";
    for(int i=0;i<n;i++)
        cout << v[i] << " \n"[i==n-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
