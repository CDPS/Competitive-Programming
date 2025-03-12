#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    string s;
    int t , n;
    cin >> t;

    while(t--){
        cin >> n;
        cout << (  (n-1)%3 == 0 ? "YES" : "NO" ) << "\n";
    }
    return 0;
}
