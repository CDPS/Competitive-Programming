#include <bits/stdc++.h>

using namespace std;

int n, m, w, h;
long long a[100000];

void solve(){

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    cin >> m;

    long long maxi = 0;
    while(m--){
        cin >> w >> h;
        maxi = max(maxi, a[w-1]);
        cout << maxi << "\n";
        maxi += h;
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    solve();

    return 0;
}
