#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
ll a[200000];

ll solve(){

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    ll sum = 0, maxi = -1;
    for(int i=0; i< n; i++){
        sum += max(a[i], a[ (i + 1) %n]);
        maxi = max(maxi, max(a[i], a[ (i + 1) %n]));
    }
    return sum - maxi;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

