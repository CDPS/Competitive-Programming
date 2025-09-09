#include <bits/stdc++.h>

using namespace std;

int n, a, b;

bool solve(){
    cin >> n >> a >> b;
    if(a< b ) a = b;
    return n%2==a%2 && n%2==b%2;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        cout << ( solve()? "YES" : "NO" ) << "\n";

    return 0;
}
