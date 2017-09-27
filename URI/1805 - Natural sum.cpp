#include <bits/stdc++.h>

using namespace std;


int main(){
    long long a,b;

    scanf("%lld %lld",&a,&b);

    a--;

    long long n = a*(a+1)/2LL;

    long long m = b*(b+1)/2LL;

    printf("%lld\n",m-n);

    return 0;
}
