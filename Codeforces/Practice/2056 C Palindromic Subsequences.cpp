#include <bits/stdc++.h>

using namespace std;

int n,t;

void solve(){

    cin >> n;
    if(n==6){
        cout << "1 1 2 3 1 2" << "\n";
        return;
    }

    for(int i = 1;i<=n-3;i++)
        cout << i << " ";

    cout << "1 2 3" << "\n";

}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}

