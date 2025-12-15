#include <bits/stdc++.h>

using namespace std;

int t, n;

void solve(){

    cin >> n;

    if(n%2==0){
        cout << "NO" << "\n";
        return;
    }

    cout << "YES" << "\n";

    if(n == 1){
        cout << "1 2" << "\n";
        return;
    }

    int evens = n/2;
    for(int i=1, j= n; i <= n - evens; i++, j-=2 )
        cout <<  j << " " << i + n << "\n";

    for(int i= (n - evens) + 1, j = n - 1; i <=n; i++, j-=2 )
        cout <<  j << " " << i + n << "\n";
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
