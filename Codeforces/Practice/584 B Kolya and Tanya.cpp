#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll m = 1e9 + 7;

ll eb (ll a, ll b){

    ll res=1, x= a%m;
    while(b>0){
        if(b%2)
            res= (res*x)%m;
        x = (x*x)%m;
        b/=2;
    }
    return res;
}

ll n;
ll solve(){
    cin >> n;
    return (eb(27, n) - eb(7, n) + m )%m;
}

int t = 1;
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
