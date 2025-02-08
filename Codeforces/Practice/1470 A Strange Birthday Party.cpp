#include <bits/stdc++.h>

using namespace std;

int a[300000], b[300000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,m;
    cin >> t;
    while(t--){

        cin >> n >> m;
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<m;i++) cin >> b[i];
        sort(a, a+n);

        long long ans = 0;
        for(int i=n-1, j = 0; i>=0;i--){
            if( j > a[i]-1 || j== m) ans+= b[ a[i]-1 ];
            else ans += b[j++];
        }

        cout << ans << "\n";
    }

    return 0;
}
