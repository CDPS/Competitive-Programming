#include <bits/stdc++.h>

using namespace std;

int t = 1, n, k;

int p[100001];

void solve(){

    cin >> n >> k;

    if(k == n){
        cout << -1 << "\n";
        return;
    }

    for(int i=1; i <=n; i++ )
        p[i] = i;

    if( (n-k)%2 == 0)
        swap(p[1], p[n]);

    for(int i = k + 3; i <=n ; i+=2)
        swap(p[i], p[i-1]);

    for(int i = 1;i <=n ; i++)
        cout << p[i] << " \n"[i==n];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}

