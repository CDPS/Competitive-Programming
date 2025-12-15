#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t,n, q, l, r;

ll   a[100000];
ll pfx[100000];
ll sfx[100000];

void solve(){

    cin >> n;

    for(int i=0;i<n;i++)
        cin >> a[i];

    pfx[0] = sfx[n-1] = 0;
    pfx[1] = sfx[n-2] = 1;

    for(int i=2;i<n;i++)
        pfx[i] = (a[i]- a[i-1] < a[i-1]-a[i-2] ) ? 1 : a[i]- a[i-1];

    for(int i=n-3;i>=0;i--)
        sfx[i] = (a[i+1] - a[i]   < a[i+2] - a[i+1] ) ? 1 : a[i+1]- a[i];

    for(int i=1;i<n;i++)
        pfx[i]+=pfx[i-1];

    for(int i=n-2;i>=0;i--)
        sfx[i]+=sfx[i+1];


    cin >> q;

    while(q--){

        cin >> l >> r;
        l--, r--;
        if(l < r)
            cout << pfx[r]-pfx[l] << "\n";
        else
            cout << sfx[r]-sfx[l] << "\n";
    }
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
