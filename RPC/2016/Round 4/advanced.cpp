#include <bits/stdc++.h>

using namespace std;

long long m = 10000000000LL;

int main(){

    long long n;

    while(scanf("%lld",&n)==1){

        if(n==0)
            break;

        long long  r=1ll;

        for(long long i=2ll;i <=n ;i++){
            r= (r%m) + (((i%m*i%m)%m)*((i-1)%m))%m;
            r= (r%m) + ( (i%m*i%m)%m);
        }

        printf("%lld\n",r);
    }
    return 0;
}
