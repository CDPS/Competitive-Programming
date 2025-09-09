#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
ll    a[200002];
ll maxi[200002];
ll q;

void solve(){

    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i+1], maxi[i+1]=max(a[i+1],maxi[i]), a[i+1]+=a[i];
    maxi[n+1] = LLONG_MAX;

    for(int i=0;i<k;i++){
        cin >> q;

        int l = 0, h = n+1, m;
        while(l< h){
            m = l + ( (h-l)/2 );
            if( maxi[m] > q)
                h = m;
            else
                l = m +1;
        }
        cout << a[l-1] << " \n"[i==k-1];
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
