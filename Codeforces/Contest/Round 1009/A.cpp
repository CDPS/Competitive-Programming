#include <bits/stdc++.h>

using namespace std;

int a[4];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){

        cin >> a[0] >> a[1] >> a[2] >> a[3];

        bool ans = (a[0]==a[1])&&(a[1]==a[2])&& (a[2]==a[3]);

        cout << (ans? "YES" : "NO") << "\n";
    }
    return 0;
}
