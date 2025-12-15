#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[100000];
int t, n;

ll f(int parity){

    vector<int> rp ;
    for(int i=0; i<n; i++)
        if(a[i] % 2 == parity)
            rp.push_back(i);

    ll ans = 0;
    for (int i = 0; i < rp.size(); i++)
        ans += abs(rp[i] - (i * 2));

    return ans;
}

ll solve(){

    cin >> n;

    int evens = 0, odds = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]%2) odds++;
        else evens++;
    }

    if(abs(odds-evens) > 1)
        return -1;

    if(odds  > evens) return f(1);
    if(evens > odds) return f(0);

    return min(f(0), f(1));
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve()  << "\n";

    return 0;
}

