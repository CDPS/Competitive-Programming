#include <bits/stdc++.h>

using namespace std;

int t, k, x;

int solve(){
    cin >> k >> x;
    while(k--) x*=2;
    return x;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
