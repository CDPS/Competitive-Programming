#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k;

vector<int> getMin(ll x){
    vector<int> a;
    while(x > 0){
        int d = x%3;
        a.push_back(d) , x/=3;
    }
    return a;
}

ll solve(){

    cin >> n >> k;

    vector<int> pows = getMin(n);

    int acc = 0;
    for(int i=0;i<pows.size();i++) acc+=pows[i];

    if(acc > k)
        return -1;

    for(int i = pows.size()-1;i>=1; i--) {
        ll room = (k - acc) / 2;
        ll take = min<ll>(pows[i], room);
        if (take)
            pows[i]-= take, pows[i-1]+=(3 * take), acc+= (2 * take);
    }

    ll ans  = 0, pow3 = 1;
    for(int i=0;i<pows.size();i++, pow3*=3)
        ans+= pows[i]*( (pow3*3) + ( i*(pow3/3) ) );

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
       cout << solve() << "\n";

    return 0;
}

