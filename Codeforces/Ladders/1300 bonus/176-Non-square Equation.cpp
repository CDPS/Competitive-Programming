#include <bits/stdc++.h>

using namespace std;

long long s(long long x){
    long long res = 0;
    while(x>0)
        res += (x%10), x/=10;
    return res;
}

long long f(long long x){
    return x*x + (s(x) *x);
}

int main(){

    long long n;
    cin >> n;

    long long sq = sqrt(n);

    int res = -1;
    for(int i = max(0ll,sq-100ll); i <=sq+100;i++){
        if(f(i)==n){
            res = i;
            break;
        }
    }
    cout  << res << "\n";
    return 0;
}
