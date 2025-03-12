#include <bits/stdc++.h>

using namespace std;

int a[200000], dga[200001];
int b[200000], dgb[200001];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, m, k, x;
    cin >> t;

    while(t--){

        cin >> n >> m >> k;

        for(int i=0;i<=n;i++) dga[i] = 0;
        for(int i=0;i<=m;i++) dgb[i] = 0;

        for(int i=0;i<k;i++) cin >> a[i];
        for(int i=0;i<k;i++) cin >> b[i];

        for(int i=0;i<k;i++)
            dga[ a[i] ]++, dgb[ b[i] ]++;


        long long ans = 0;
        for(int i=0;i<k;i++)
            ans+= k -dga[a[i]]-(dgb[b[i]]-1);

        cout << ans/2 << "\n";
    }
    return 0;
}
