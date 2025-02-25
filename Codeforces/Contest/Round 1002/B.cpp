#include <bits/stdc++.h>

using namespace std;

int a[200000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, k;
    cin >> t;

    while(t--){

        cin >> n >> k;
        for(int i=0;i<n;i++) cin >> a[i];

        int ans;

        if(k==n){
            ans = 1;
            for(int i=1;i<n && a[i]==ans ;i+=2)ans++;
        }else{
            ans = 2;
            for(int i= 1; i <  n - (k-2); i++)
                if(a[i]!= 1 ){ ans = 1; break; }
        }

        cout << ans << "\n";
    }
    return 0;
}
