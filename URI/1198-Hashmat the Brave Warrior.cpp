#include <bits/stdc++.h>

using namespace std;


int main(){

    long long v,t;

    while(scanf("%lld %lld",&v,&t)==2){

        long long res = t-v;
        printf("%lld\n",abs(res) );
    }
}
