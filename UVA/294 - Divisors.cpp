#include <bits/stdc++.h>


using namespace std;

long long countD(long long n){

    long long res =1;

    for(long i=2; i<=sqrt(n);i=(i==2)?i+1:i+2){
       int a=0;
        while(n%i==0){
                n/=i;
                a++;
        }
        res*=(a+1);
    }
    if(n!=1)res*=(1+1);
    return res;
}

int main(){

    int t;
    scanf("%d",&t);
    while(t--){

        long long u,l;
        scanf("%lld %lld",&l,&u);

        long long maxx=0;
        long long j=0;
        for(long long i=l;i<=u;i++){
            long long r=countD(i);
            if(r > maxx){
                maxx=r;
                j=i;
            }
        }

        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,u,j,maxx);

    }
    return 0;
}
