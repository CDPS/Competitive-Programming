#include <bits/stdc++.h>

using namespace std;

int t, n, w;

int solve(){
    cin >> n >> w;
    return n - n/w;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
