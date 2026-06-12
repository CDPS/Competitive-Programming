#include <bits/stdc++.h>

using namespace std;

int t, n , w, d;

int solve(){

    cin >> n >> w >> d;

    int towers = d/w + 1;

    return (n + towers - 1)/towers;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

