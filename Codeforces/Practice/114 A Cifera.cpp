#include <bits/stdc++.h>

using namespace std;

long long t =1 , k , l;

void solve(){

    cin >> k >> l;

    if(l < k != 0){
        cout << "NO" << "\n";
        return;
    }

    int ans = 0;
    long long initial  = k;
    while(k < l)
        ans++, k*=initial;

    if(k != l){
        cout << "NO" << "\n";
        return;
    }

    cout << "YES" << "\n" << ans << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
