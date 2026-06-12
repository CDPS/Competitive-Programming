#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll  x;

bool check(ll n){
    ll cube = round(cbrt(n));
    return (cube * cube *cube) == n;
}

bool solve(){

    cin >> x;
    for(ll  a = 1; a*a*a<=x; a++ ){
        ll b = x - (a*a*a);
        if(check(b) && b != 0)
            return true;
    }

    return false;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";
    return 0;
}
