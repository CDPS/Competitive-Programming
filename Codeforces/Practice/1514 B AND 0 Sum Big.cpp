#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;

ll m = 1e9 + 7, n , k;
ll eb(ll a,ll b){
    ll res=1, x= a%m;
    while(b>0){
        if(b%2)
            res= (res*x)%m;
        x = (x*x)%m;
        b/=2;
    }
    return res;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n >> k;
        cout << eb(n, k) << "\n";
    }

    return 0;
}

