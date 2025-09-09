#include <bits/stdc++.h>

using namespace std;

int t, n, x;

int solve(){
    if(n==1 && x==0) return -1;
    int bits = __builtin_popcount(x);
    if(bits  >= n ) return x;
    int rest = n - bits;
    if(rest%2==0) return x + rest;
    if(x > 1) return x + rest + 1 ;
    if(x==0 && n>1 ) return n+3;
    if(x==1) return n + 3;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);


    cin >> t;
    while(t--){

        cin >> n >> x;
        cout << solve()<< "\n";
    }
    return 0;
}
