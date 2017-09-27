#include <bits/stdc++.h>

using namespace std;

int acc[10001];

long f(long n){
    return (n*n+n+41);
}

int isPrime(long n){
    if(!(n&1))
        return 0;
    for(long i=3;i*i<=n;i+=2)
        if(n%i==0)
            return 0;
    return 1;
}

int main(){

    int a,b;
    for(int i=0;i<=10000;i++){
        if(isPrime(f(i)))
            acc[i]=1;
    }
    for(int i=1;i<=10000;i++)
        acc[i]+= acc[i-1];

    while(scanf("%d %d",&a,&b)==2){
        int res= acc[b]- acc[a]+ isPrime(f(a));
        int total= b-a+1;
        printf("%.2lf\n",(double(res)/double(total))*100.0 +1e-6);
    }
    return 0;
}
