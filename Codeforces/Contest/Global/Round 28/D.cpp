#include <bits/stdc++.h>

using namespace std;

int oo = 2000000000;

int a[300000], b[300000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,m;
    cin >> t;

    while(t--){

        cin >> n >> m;

        for(int i=0;i<n;i++)
            cin >> a[i], a[i] = max(a[0], a[i]);
        sort(a, a+n);

        for(int i=0;i<m;i++){
            cin >> b[i];
            auto it =  lower_bound( a, a + n, (b[i] <= a[0])?  oo: b[i] );
            b[i] = (it != a + n)? n -(it - a) : 0 ;
        }
        sort(b, b+m);

        for(int i=1; i<=m;i++){
            long long ans = 0;
            for(int j=i-1;j<m;j+=i)
                ans+= b[j] + 1;
            cout << ans << " \n"[i == m];
        }
    }
    return 0;
}
