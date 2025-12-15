#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, t;

ll a[100000];
ll b[100000];

ll solve(){


    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    ll maxi = 0, mini = 0 ;
    for(int i=0;i<n;i++){

        ll maxip = max( maxi - a[i], b[i] - mini );
        ll minip = min( mini - a[i], b[i] - maxi );

        maxi = maxip;
        mini = minip;
    }

    return maxi;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);


    cin >> t;
    while(t--)
        cout << solve() << "\n";

}
