#include <bits/stdc++.h>

using namespace std;

int t =1, k, d;

void solve(){

    cin >> k >> d;

    if(d==0 && k > 1){
        cout << "No solution" << "\n" ;
        return;
    }

    cout << d; k--;
    while(k--)
        cout << 0;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
    solve();

    return 0;
}

