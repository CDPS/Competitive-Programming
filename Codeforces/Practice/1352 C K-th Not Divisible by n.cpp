#include <bits/stdc++.h>

using namespace std;

int t, n, k;

int solve(){

    cin >> n >> k;

    return k + (k-1)/(n-1);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

