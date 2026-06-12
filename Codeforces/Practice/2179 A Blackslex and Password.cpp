#include <bits/stdc++.h>

using namespace std;

int t, k , x;

int solve(){
    cin >> k >> x;
    return k*x + 1;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";
}

