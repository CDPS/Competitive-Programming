#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n, x;

int solve(){

    cin >> n ;

    int zeroes = 0;
    ll acc = 0;
    for(int i=0;i<n;i++ ){
        cin >> x;
        if(x != 0) zeroes++;
        acc += x;
    }

    return min( (ll)zeroes,  acc - n + 1);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    while(t--)
        cout << solve() << "\n" ;

    return 0;
}


