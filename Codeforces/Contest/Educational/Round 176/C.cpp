#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll oo = 1e9;

ll    a[200001];
ll  sum[200001];
ll  n, m;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){

        cin >> n >> m;

        for(int i=0;i<m;i++)
            cin >> a[i], a[i] = min(a[i], n-1), sum[i+1] = 0;
        a[m] = oo;

        sort(a, a + m);
        for(int i=1;i<=m;i++)
            sum[i] = a[i-1] + sum[i-1];

        ll ans = 0;
        for(int i=0;i<m-1;i++){

            ll x = n - a[i];

            int l = i+1, h = m, mid;
            while(l<h){
                mid = l + ((h-l)/2);
                if( a[mid] >= x )
                     h = mid;
                else l = mid +1;
            }
            if(l == m) continue;

            ans = ans +  (sum[m] - sum[l]) - ((x-1)*(m-l));
        }

        cout << ans * 2ll << "\n";
    }

    return 0;
}
