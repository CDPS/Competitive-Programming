#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

ll solve(){

    cin >> n;

    ll ans = 0, pow = 3, acc = 0;

    while(n > 0){
        int d = n%3;
        ans+= d*(pow + ( acc*(pow/9) ) );;
        pow*=3;
        acc++;
        n/=3;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
       cout << solve() << "\n";

    return 0;
}

