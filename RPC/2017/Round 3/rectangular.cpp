#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

#define m 1000000007LL

ll mul(ull  a, ull b, ull  mod) {
    ull  ret = 0;
    for (a %= mod, b %= mod; b != 0; b >>= 1, a <<= 1, a = a >= mod ? a - mod : a) {
        if (b&1) {
            ret += a;
            if (ret >= mod) ret -= mod;
        }
    }
    return ret;
}


ll powm (ll a, ll b){
   ll ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = ((ans%m)*(a%m) )%m;
        a = ( (a%m)*(a%m) )%m;
        b >>= 1;
    }
    return ans;
}

ll sum(ll x){
    return (((mul(x,x+1,m))%m)*(powm(2,m-2)%m))%m;
}

ll sumsqrt(ll x){

    ll p1 = mul(x,x+1,m);
    ll p2 = ( mul(2,x,m) + 1 )%m;
    ll p3 =  mul(p1,p2,m);
    ll p4 = mul(p3,powm(6,m-2),m);
    return p4;
}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);

    long caseno=1,t;


    cin >> t;
    ll n,l,M,k,q,p1,p2,p3,p4,p5,p6,p7,total;

    while(t--){

       cin >> n;

        l = (n/2) + 1;

        M = n -l +1;

        k = ( (sum(l -1)%m) + (1%m) )%m;
        k = ( (k%m) - (l%m) +m)%m;

        p1 = mul(2,M,m); p1 = mul(p1,k,m);  p1 =mul(p1,l,m);

        q = (1 + (((2%m)*((l-1)%m))%m))%m;
        p2 = ((q%m)*(sum(M)%m))%m;

        p3 = sumsqrt(M);

        p4 = ((p2%m) + (p3%m) )%m;

        p5 = ( (p4%m)*(l%m) )%m;

        p6 = ( (M%m)*(l%m) )%m; p6 = ((p6%m)*(l%m))%m;
        p7 = ( (M%m)*(l%m) )%m;


        total = ( (p1%m)  + (p5%m) )%m;
        total = ( (total%m)  + (p6%m) )%m;
        total = ( (total%m)  - (p7%m) + m)%m;
        total = mul(total, powm(2,m-2),m );

        cout << "Case #" << caseno++ << ": " << total << "\n";
    }
    return 0;
}
