#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){
        cin >> n;
        cout << (n/15)*3 + min(3, n%15 + 1 ) << "\n";
    }

    return 0;
}
