#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    ll prev0 = 1, prev1 = 0, prev2 = 0, prev3 = 0  ;
    for(int i=1;i<=n;i++){

        ll curr0 = (prev1 +  prev2 +  prev3)%mod;
        ll curr1 = (prev0 +  prev2 +  prev3)%mod;
        ll curr2 = (prev1 +  prev0 +  prev3)%mod;
        ll curr3 = (prev1 +  prev2 +  prev0)%mod;

        prev0 = curr0, prev1 = curr1, prev2 = curr2, prev3 = curr3;
    }

    cout << prev0 << "\n";

}
