#include <bits/stdc++.h>

using namespace std;

int t, n, x;

int a[200001];

int solve(){

    cin >> n;
    for(int i=0; i < n ; i++) cin >> a[i];

    int ans = 0;
    for(int i=1; i < n; i++)
        ans+= ( abs(a[i]- a[i-1]) == __gcd(a[i], a[i-1]) );

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

