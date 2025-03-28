#include <bits/stdc++.h>

using namespace std;

int a[200001];

int main(){

    int t, n, m, u, v;
    cin >> t;

    while(t--){

        cin >> n >> m;

        for(int i=1;i<=n;i++) a[i] = n+1;

        while(m--){
            cin >> u >> v;
            if(u > v) swap(u,v);
            a[u] = min(a[u], v);
        }

        for(int i = n-1; i>=1; i--)
            a[i] = min(a[i], a[i + 1]);

        long long ans = 0;
        for(int i=1;i<=n;i++)
            ans += (a[i]-1)-(i-1);

        cout << ans << "\n";
    }
    return 0;
}
