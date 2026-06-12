#include <bits/stdc++.h>

using namespace std;

int t, n;
int p[200001];

void solve(){

    cin >> n;

    if(__builtin_popcount(n) == 1 ){
        cout << -1 << "\n";
        return;
    }

    p[n]  = 1;
    p[1]  = n- (n%2);
    for(int i=2; i<=n-2;i+=2)
        p[i] = i + 1, p[i+1] = i;

    if(n%2)
        p[n-1]= n;
    else
        swap(p[1], p[ n - (1 << __lg(n))  ]);

    for(int i=1;i<=n;i++)
        cout << p[i] << " \n"[i==n];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}



