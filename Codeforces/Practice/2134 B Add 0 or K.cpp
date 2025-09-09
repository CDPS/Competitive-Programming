#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll k;
ll a[100000];
ll primes[11] = {2,3,5,7,11,13,17,19,23,29,31};

ll eb(ll a,ll b, ll m){
    ll res=1, x= a%m;
    while(b>0){
        if(b%2)
            res= (res*x)%m;
        x = (x*x)%m;
        b/=2;
    }
    return res;
}

void solve(){

    cin >> n >> k;

    for(int i=0;i<n;i++)
        cin >> a[i];

    ll p = -1;
    for(int i=0;i<11;i++){
        if(k%primes[i]!=0){
            p = primes[i];
            break;
        }
    }

    ll inv = eb(k,p-2, p);
    for(int i=0;i<n;i++){
        ll r = (p - (a[i] % p)) % p;
        ll s = (r * inv) % p;
        a[i]= a[i] + s * k;
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
        for(int i=0;i<n;i++)
            cout<< a[i] << " \n"[i==n-1];
    }

    return 0;
}

