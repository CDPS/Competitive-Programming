#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n;
    cin >> t;

    while(t--){
        cin >> n;
        int k =1, ans = 1;
        while( k < n)
            ans++, k = k*2 +2;
        cout << ans << "\n";
    }
    return 0;
}

