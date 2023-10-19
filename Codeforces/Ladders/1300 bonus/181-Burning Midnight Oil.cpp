#include <bits/stdc++.h>

using namespace std;

long n, k;

long f(long v, long k){
    long res = v;
    long pow = k;
    while(v/k > 0){
        res += v/k;
        k*=pow;
    }
    return res;
}

long upperBound(long x){
    long l = 1, h = x, m;
    while(l< h){
         m = l + ( (h-l)/2 );
        if( f(m,k) >= x)
             h = m;
        else l = m +1;
    }
    return l;
}

int main(){
    cin >> n >> k;
    cout << upperBound(n) << "\n";
    return 0;
}
