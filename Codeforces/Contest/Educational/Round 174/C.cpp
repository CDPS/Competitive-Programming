#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 998244353ll;
ll a[200000], p[200000];

ll mul(unsigned long long  a, unsigned long long  b) {
    unsigned  ret = 0;
    for (a %= mod, b %= mod; b != 0; b >>= 1, a <<= 1, a = a >= mod ? a - mod : a) {
        if (b&1) {
            ret += a;
            if (ret >= mod)    ret -= mod;
        }
    }
    return ret;
}

ll powm(ll a,ll b){
    ll ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){

        cin >> n;

        for(int i=0;i<n;i++)
            cin >> a[i], p[i] = a[i]==2;

        ll sum = 0, acc = 0;

        int init = 0;
        while (init < n && a[init] != 1) init++;

        for(int i=init + 1;i<n;i++){
            p[i]+=p[i-1];
            if( a[i] == 3) sum = (sum + powm(2ll, p[i]))%mod, acc++;
        }

        ll ans = 0;
        for(int i=init;i<n;i++){
            if(a[i] == 3)
                sum = ( sum - powm(2ll, p[i]) + mod )%mod, acc--;
            if(a[i] == 1)
                ans = ((ans + mul(sum, powm( powm(2ll, p[i]),mod-2ll ) ) )%mod - acc + mod)%mod;
        }

        cout << ans << "\n";
    }

    return 0;
}
