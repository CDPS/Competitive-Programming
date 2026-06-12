#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll s, m;

ll getFirst(){
    for(int i=0; i <= 60 ; i++)
        if( (m&(1ll << i)) !=0  )
            return (1ll << i);
    return -1;
}

bool check(ll n){

    ll curr = s;
    for(int i = 60; i>=0; i--){
        if( (m&(1ll<< i)) != 0  ){
            ll current_pow = (1ll << i);
            ll slots = min(n, curr/current_pow);
            curr-= slots*current_pow;
        }
    }
    return curr == 0;
}

ll solve(){

    cin >> s >> m;

    if(s % getFirst() != 0)
        return -1;

    ll l = 0, h = 1e18, mid;
    while(l< h){
        mid = l + ( (h-l)/2 );
        if( check(mid) )
             h = mid;
        else l = mid +1;
    }

    return l;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

