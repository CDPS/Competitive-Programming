#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << (n%33==0? "YES" : "NO") << "\n";
    }
    return 0;
}
