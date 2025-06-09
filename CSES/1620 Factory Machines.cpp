#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[200000], t;

int n;

bool check(ll x){
    ll acc = 0;
    for(int i=0;i<n;i++){
        acc+= x/a[i];
        if(acc >= t)
            return true;
    }
    return false;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> t;

    for(int i=0;i<n;i++) cin >> a[i];

    ll l = 0, h = 1e18, m;
    while(l< h){
        m = l + ( (h-l)/2 );
        if(check(m))
             h = m;
        else l = m +1;
    }

    cout << l << "\n";

    return 0;
}
