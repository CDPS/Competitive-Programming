#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll m = 1e9 + 7;

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

    int t;
    ll a, b;
    cin >> t;

    while(t--){
        cin >> a >> b;
        cout << eb(a,b) << "\n";
    }
    return 0;
}
