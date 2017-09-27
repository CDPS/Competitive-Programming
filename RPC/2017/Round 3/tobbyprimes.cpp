#include <bits/stdc++.h>

using namespace std;

const int rounds=10;

typedef unsigned long long ull;
typedef long long ll;

ll gcd(ll a, ll b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}

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

bool witness(ll a,ll n){

    ll u=n-1;
    ll t=0;

    if(n==a) return true;

    while(u%2==0){ t++; u>>=1; }

    ll next = powm(a,u,n);
    if(next==1 )return false;
    ll last;
    for(int i=0;i<t;i++){
        last = next;
        next = mul(last, last,n);
        if(next==1){
            return last != n-1;
        }
    }
    return next !=1;
}

bool miller_rabin(ull n, int it= rounds){
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 0; i < it; ++i) {
        ll a = rand() % (n - 1) + 1;
        if (witness(a, n)) {
            return false;
        }
    }
    return true;
}

ll pollard_rho(ll n){
    ll x, y, i = 1, k = 2, d;
    x = y = rand() % n;
    while (1) {
        ++i;
        x = mul(x, x, n);
        x += 2;
        if (x >= n) x -= n;
        if (x == y) return 1;
        d = gcd(abs(x - y), n);
        if (d != 1) return d;
        if (i == k) {
            y = x;
            k *= 2;
        }
    }
    return 1;
}

vector<ll> factorize(ll n) {
    vector<ll> ans;
    if (n == 1)
    return ans;
    if (miller_rabin(n)) {
        ans.push_back(n);
    } else {
        ull d = 1ull;
        while (d == 1)
            d = pollard_rho(n);
        vector<ll> dd = factorize(d);
        ans = factorize(n / d);
        for (int i = 0; i < dd.size(); ++i)
            ans.push_back(dd[i]);
    }
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    srand(time(NULL));

    int t;
    cin  >> t;
    unsigned long long n;

    while(t--){
        cin >> n;
        vector <ll> ans = factorize(n);
        sort(ans.begin(),ans.end());

        for(int i=0;i<ans.size()-1;i++)
            cout << ans[i] << " ";
        cout << ans[ans.size()-1] << "\n";
    }

    return 0;
}
