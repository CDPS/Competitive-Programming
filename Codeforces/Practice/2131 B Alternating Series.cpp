#include <bits/stdc++.h>

using namespace std;

 int t, n;

void solve(){

     for(int i=0;i<n-2;i+=2)
        cout << "-1 3 ";

    cout << ( (n%2==0)? "-1 2" : "-1") << "\n";
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);


    cin >> t;

    while(t--){

        cin >> n;

        solve();
    }
    return 0;
}

