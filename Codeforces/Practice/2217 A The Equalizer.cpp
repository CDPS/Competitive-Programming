#include <bits/stdc++.h>

using namespace std;

int t, n, k, x;

bool solve(){

    cin >> n >> k;

    int sum = 0;
    for(int i=0; i < n ; i++)
        cin >> x, sum+= x;

    if(sum % 2)  return true;
    if(n * k % 2 == 0) return true;

    return false;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << ( solve() ? "YES" : "NO" ) << "\n";

    return 0;
}
