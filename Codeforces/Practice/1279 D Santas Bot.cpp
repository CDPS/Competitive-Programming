#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int t = 1, n, m, x;

vector<int> a[1000000];
int freq[1000001];
ll inv_k[1000000];

ll eb(ll a, ll b){

    ll res=1, x= a%MOD;
    while(b>0){
        if(b%2)
            res= (res*x)%MOD;
        x = (x*x)%MOD;
        b/=2;
    }

    return res;
}

ll solve(){

    cin >> n;

    for(int i=0; i < n; i++){
        cin >> m;
        for(int j = 0; j < m; j++)
            cin >> x, a[i].push_back(x), freq[x]++;
        inv_k[i] = eb(m, MOD - 2);
    }

    ll ans = 0;
    ll inv_n2 = eb(1ll*n*n, MOD - 2);

    for(int i=0; i < n; i++){
        for(int j = 0; j < a[i].size(); j++){
            ll curr = (freq[ a[i][j] ] * inv_n2)% MOD;
            curr = ( curr*inv_k[i] )%MOD;
            ans = (ans + curr)%MOD;
        }
    }
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
