#include <bits/stdc++.h>

using namespace std;

int t =1, n, k;

void solve(){

    cin >> n >> k;

    if(n== 1 && k == 0){
        cout  << 1 << "\n";
        return;
    }

    if(n== 1){
        cout  << -1  << "\n";
        return;
    }

    int spaces = n/2;
    if(k < spaces ){
        cout  << -1  << "\n";
        return;
    }


    int x = k-spaces+1;

    cout << x << " " << x*2 << " ";

    int curr= x*2+1;
    for(int i=0; i < spaces - 1; i++, curr+=2)
        cout << curr  << " " << curr + 1<< " ";

    if(n%2)
        cout << curr + 1 << "\n";
    else
        cout << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
