#include <bits/stdc++.h>

using namespace std;

bitset<65001> m;

void sieve(int n){
    m.set();
    for(int i=0;i<=n;i++)
        m[i]=1;
    m[0]=m[1]=0;

    for(long long i=2;i*i<=n;i++){
        if(m[i]){
            for(long long j=i+i;j<=n;j+=i)
                m[j]=0;
        }
    }
}

long long binaryExpo(long long b, long long e, long long m){
    long long res=1, x= b;
    while(e>0){
        if(e%2)
            res = ( (res%m) * (x%m) )%m;
        x =  ( (x%m)  * (x%m) )%m;
        e/=2;
    }
    return res;
}

bool test(int n){
    for(int i=2;i<=n-1;i++){
        if( i != binaryExpo(i,n,n))
            return false;
    }
    return true;
}

int main(){
    sieve(65000);
    int n;

    while(scanf("%d",&n)==1 && n){

        if(m[n]){
             printf("%d is normal.\n", n);
        }else{
            if(test(n))
               printf("The number %d is a Carmichael number.\n", n);
            else
                printf("%d is normal.\n",n);
        }
    }
    return 0;
}
