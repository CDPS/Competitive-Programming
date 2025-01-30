#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, k;
    cin >> t;

    while(t--){

        cin >> n >> k;

        int ans = 1e9;
        for(int i=1;i*i<=n && i<=k;i++){
            if(n%i==0){
                int d1 = n/i;
                ans = min(ans, d1);
                if(d1 <= k ) ans = min(ans, i);
            }
        }

        cout << ans << "\n";

    }
    return 0;
}
