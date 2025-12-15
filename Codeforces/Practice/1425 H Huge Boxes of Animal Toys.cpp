#include <bits/stdc++.h>

using namespace std;

int t, a, b, c, d;

void solve(){

    cin  >> a >> b >> c >> d;
    cout <<  ((a+b)%2==1 && a+d> 0? "Ya" : "Tidak" ) << " ";
    cout <<  ((a+b)%2==1 && b+c> 0? "Ya" : "Tidak" ) << " ";
    cout <<  ((a+b)%2==0 && b+c> 0? "Ya" : "Tidak" ) << " ";
    cout <<  ((a+b)%2==0 && a+d> 0? "Ya" : "Tidak" ) << "\n";
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    while(t--)
        solve();

    return 0;
}
