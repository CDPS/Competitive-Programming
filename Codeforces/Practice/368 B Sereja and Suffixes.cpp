#include <bits/stdc++.h>

using namespace std;

int t =1;
int n, m, x;

int   a[100001];
bool  s[100001];
int sfx[100002];

void solve(){

    cin >> n  >> m;

    for(int i=1;i<=n;i++)
        cin >> a[i];

    for(int i=n;i>=1;i--){
        sfx[i] =  !s[a[i]]  + sfx[i+1];
        s[a[i]] = true;
    }

    while(m--)
        cin >> x, cout << sfx[x] << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        solve();

    return 0;
}
