#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t = 1, n;

ll k;
ll a[100000];
ll b[100000];

bool check(ll x){

    ll curr = k;
    for(int i=0;i<n;i++){

        if(b[i] >= a[i] * x) continue;

        ll needed = (a[i]*x) - b[i];
        if(needed > curr) return false;

        curr-= needed;
    }

    return true;
}

ll solve(){

    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];


    ll l = 0, h = 1e10 ,m;

    while(l< h){
        m = l + ( (h-l)/2 );
        if( !check(m) )
             h = m;
        else l = m +1;
    }

    return l - 1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
