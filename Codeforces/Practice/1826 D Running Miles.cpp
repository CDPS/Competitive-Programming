#include <bits/stdc++.h>

using namespace std;

int   a[100000];
int sfx[100000];
int pfx[100000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){

        cin >> n;

        for(int i=0;i<n;i++) cin >> a[i];

        pfx[0] = a[0];
        for(int i=1;i<n;i++)
            pfx[i] = max(pfx[i-1], a[i] + i);

        sfx[n-1] = a[n-1] - (n-1);
        for(int i=n-2;i>=0;i--)
            sfx[i] = max(sfx[i+1], a[i] - i);

        int ans = 0;
        for(int i=1;i<n-1;i++)
            ans= max( ans , a[i] + pfx[i-1] + sfx[i+1] );

        cout << ans << "\n";
    }

    return 0;
}
