#include<bits/stdc++.h>

using namespace std;

int a[200002];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, x, ans = 0;

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> x, a[x] = i+1;

    for(int i=1;i<=n;i++)
        if(a[i] > a[i+1]) ans++;

    cout << ans << "\n";

    return 0;
}
