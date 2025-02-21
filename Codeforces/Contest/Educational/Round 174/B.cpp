#include <bits/stdc++.h>

using namespace std;

int a[701][701];
int acc[500000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n , m, num;
    cin >> t;
    while(t--){

        cin >> n >> m;

        for(int i=0;i<=n*m;i++) acc[i] = 0;

        int maxi = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j];
                acc[  a[i][j] ] = max(acc[a[i][j]], 1 );
                if(a[i][j]== a[i-1][j] || a[i][j] == a[i][j-1])
                    acc[ a[i][j] ] = max(acc[a[i][j]], 2 );
                maxi = max(maxi, acc[ a[i][j]]);
            }
        }
        int ans = -maxi;
        for(int i=0;i<=n*m;i++) ans+=acc[i];
        cout << ans << "\n";
    }

    return 0;
}
