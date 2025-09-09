#include <bits/stdc++.h>

using namespace std;

int a[10];
int b[10];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, k, x, mod;
    cin >> t;

    while(t--){

        cin >> n;

        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];

        int ans = 0;
        for(int i=0;i<n;i++){
            if(a[i] > b[i])
                ans+= a[i]-b[i];
        }

        cout << ans + 1 << "\n";
    }
    return 0;
}
