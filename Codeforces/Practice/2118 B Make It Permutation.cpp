#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){
        cin >> n;
        cout << 2*n << "\n";
        for(int i=1;i<=n;i++){
            cout << i << " " << 1 << " " << i << "\n";
            cout << i << " " << min(n, i+1) << " " << n << "\n";
        }
    }
    return 0;
}
