#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t = 1, n;

void solve(){

    cin >> n;

    vector<int> coprimes;
    for(int i= 1; i <= n-1; i++)
        if(__gcd(i, n) == 1 )
            coprimes.push_back(i);

    ll R = 1;
    for(int i=0; i < coprimes.size(); i++)
        R = (coprimes[i]*R)%n;

    cout << coprimes.size() - (R != 1) << "\n";
    for(int i=0; i < coprimes.size(); i++){
        if(R == 1 || coprimes[i] != R)
            cout << coprimes[i] << " ";
    }

    cout << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
