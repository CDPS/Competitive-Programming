#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[100];

int n, t;

ll solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    ll mod = 2;
    for(int i=1;i<=60;i++, mod*=2){
        set<ll> st;
        for(int j=0;j<n;j++)
            st.insert(a[j]%mod);
        if(st.size()==2) break;
    }

    return mod;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
