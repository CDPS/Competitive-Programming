#include <bits/stdc++.h>

using namespace std;

int n, m;

void solve(){

    cin >> n >> m;

    if(n == m ){
        cout << n-1 << " " << n << "\n";
        return;
    }

    int mini = min(n, m);
    int maxi = max(n, m);

    int left = n + m - (2*mini - 1);
    cout <<  mini + left - 2  << " " << mini << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    solve();

    return 0;
}
