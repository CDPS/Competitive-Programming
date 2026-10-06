#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
ll solve(){

    cin >> n;

    ll ans = 0;
    for(int i=1; i<=n; i++){
        ll div = n/i;
        ans+= (div*div);
    }

    return ans;
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
        cout << solve() << "\n";
    return 0;
}