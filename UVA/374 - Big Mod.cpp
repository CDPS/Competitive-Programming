#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll mul(ull  a, ull b, ull  mod) {
    ull  ret = 0;
    for (a %= mod, b %= mod; b != 0; b >>= 1, a <<= 1, a = a >= mod ? a - mod : a) {
        if (b&1) {
            ret += a;
            if (ret >= mod)    ret -= mod;
        }
    }
    return ret;
}

ll powm(ll a,ll b,ll c){
    ll ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = mul(ans, a, c);
        a = mul(a, a, c);
        b >>= 1;
    }
    return ans;
}

int main(){
    ll b,p,m;
    while(cin >> b >> p >> m)
        cout << powm(b,p,m) << "\n";
    return 0;
}
