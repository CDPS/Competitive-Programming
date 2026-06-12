#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll r, l;

ll solve(){

    cin >> l >> r;
    for(int i=0;i<=61;i ++)
        if( (l | (1ll<<i)) <= r)
            l|=(1ll<<i);

    return l;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n" ;

    return 0;
}
