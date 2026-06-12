#include <bits/stdc++.h>

using namespace std;

const int mod = 210;

int t = 1, n;

void solve(){

    cin >> n;

    if(n< 3){
        cout << -1 << "\n";
        return;
    }

    if(n== 3){
        cout << mod << "\n";
        return;
    }

    int curr = 1;
    for(int i=0; i< n-1;i++)
        curr = (curr*10)%mod;

    int missing = 210 - curr;

    cout << 1;
    for(int i=0; i < n -4; i++)
        cout << 0;
    cout << setfill('0') << setw(3) << missing << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
