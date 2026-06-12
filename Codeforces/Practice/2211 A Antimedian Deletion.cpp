#include <bits/stdc++.h>

using namespace std;

int t, n;
int p[1000];

void solve(){


    cin >> n;
    for(int i=0; i < n; i++ ) cin>> p[i];

    if(n ==1){
        cout << 1 << "\n";
        return;
    }

    for(int i = 0 ; i < n; i++)
        cout << 2 << " \n"[i == n-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
