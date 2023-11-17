#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n, res=0 , pow1 = 1ll, pow2 = 2ll;

    cin >> n;
    while(n){
        int d = n %10;
        res = (d==4)? res + pow1 : res + pow2;
        pow1*=2;
        pow2*=2;
        n/= 10;
    }
    cout  << res << "\n";
    return 0;
}
