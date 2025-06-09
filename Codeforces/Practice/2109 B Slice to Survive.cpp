#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int get(ll x){
    int ans = 0;
    while(x > 1)
        x=(x+1)/2, ans++;
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    ll t, n, m, a, b;
    cin >> t;

    string x;
    while(t--){

        cin >> n >> m >> a >> b;

        ll nd = min(a, n-a+1);
        ll md = min(b, m-b+1);

        cout << min(  get(n) + get(md), get(nd) + get(m)) + 1 << "\n";
    }

    return 0;
}
