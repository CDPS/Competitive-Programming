#include <bits/stdc++.h>

using namespace std;

int main(){

    long n,k;

    while(scanf("%ld %ld",&n,&k)){

        if(n==0 && k==0) break;

        long m = max(n-k,k);
        long r = min(n-k,k);

        long res= 1;

        for(long i=1;i<=r;i++) {
            res = res * (m+i);
            res = res / i;
        }

        printf("%ld\n",res);
    }
    return 0;
}
