#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(){
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if(n%2)  return l;
    if(n==2) return -1;
    ll pow2 = (1ll<< int(log2(l)) + 1);
    if(pow2 > r) return -1;
    return k<=n-2? l : pow2;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        cout << solve() << "\n";
    return 0;
}
