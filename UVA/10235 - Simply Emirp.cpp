#include <bits/stdc++.h>

using namespace std;

bitset<1000001> m;

void sieve(int n){
    m.set();
    for(int i=2;i<=n;i++)
        m[i]=1;
    m[0]=m[1]=0;
    for(long long i=2;i*i<=n;i++){
        if(m[i]){
            for(long long j=i+i;j<=n;j+=i)
                m[j]=0;
        }
    }
}

int reverseInt(int n){
    int res=0;
    while(n){
        int r = n%10;
        res = res*10+r;
        n/=10;
    }
    return res;
}

int main(){

    sieve(1000000);
    int n;
    while(scanf("%d",&n)==1){
        int nr = reverseInt(n);
        if(!m[n]){
            printf("%d is not prime.\n",n);
        }else if(nr!= n && m[nr]){
            printf("%d is emirp.\n",n);
        }else{
            printf("%d is prime.\n",n);
        }
    }
    return 0;
}
