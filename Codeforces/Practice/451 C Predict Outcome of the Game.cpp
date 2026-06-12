#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll t, n, k, d1, d2;

bool check(ll w1, ll w2, ll w3){
    return w1 >=0 && w1 <= n/3 && w3 >=0 && w3 <= n/3 && w2 <= n/3;
}

bool solve(){

    cin >> n >> k >> d1 >> d2;

    if(n%3 != 0 ) return false;

    bool ans = false;
    if( k-d1-d2 >=0 && (k-d1-d2)%3==0 ){
        ll w2 = (k-d1-d2)/3;
        ans |= check(w2 + d1, w2, w2 + d2);
    }

    if( k-d1+d2 >=0 && (k-d1+d2)%3==0 ){
        ll w2 = (k-d1+d2)/3;
        ans |= check(w2 + d1, w2, w2 - d2);
    }

    if( k+d1-d2 >=0 && (k+d1-d2)%3==0 ){
        ll w2 = (k+d1-d2)/3;
        ans |= check(w2 - d1, w2, w2 + d2);
    }

    if( k+d1+d2 >=0 && (k+d1+d2)%3==0 ){
        ll w2 = (k+d1+d2)/3;
        ans |= check(w2 - d1, w2, w2 - d2);
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "yes" : "no") << "\n";

    return 0;
}
