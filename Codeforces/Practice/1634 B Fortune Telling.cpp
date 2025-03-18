#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    long long x, y, acc, k;
    cin >> t;

    while(t--){

        cin >> n >> x >> y;
        acc = 0;

        for(int i=0;i<n;i++)
            cin >> k, acc+=k;

         cout << ((x + acc)%2 == y%2 ? "Alice" : "Bob" ) << "\n";
    }
    return 0;
}
