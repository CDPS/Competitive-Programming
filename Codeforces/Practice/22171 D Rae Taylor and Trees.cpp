#include <bits/stdc++.h>

using namespace std;

int n, t;
int a[200000];

bool solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> sfx(n), pfx(n);

    sfx[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--) sfx[i] = max(a[i], sfx[i+1]);

    pfx[0] = a[0];
    for(int i=1;i<n;i++) pfx[i] = min(a[i], pfx[i-1]);

    for(int i=0;i<n-1;i++)
        if(pfx[i] > sfx[i+1])
            return false;

    return true;
}
int main(){

    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> t;
    while(t--)
        cout << ( solve()? "YES" : "NO" ) << "\n";


    return 0;
}
