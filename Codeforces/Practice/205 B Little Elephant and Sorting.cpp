#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t = 1, n;
ll a[100000];

ll solve(){

    cin >> n;
    for(int i=0; i < n; i++ ) cin >> a[i];

    ll ans = 0;
    for(int i=0; i < n -1 ; i++)
        if(a[i] > a[i+1])
            ans+= a[i] - a[i+1];

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
