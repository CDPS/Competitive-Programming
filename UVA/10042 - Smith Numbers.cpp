#include <bits/stdc++.h>

using namespace std;

bitset<32001> m;
vector<int> primes;

void sieve(int n){
    m.set();
    for(int i=2;i<=n;i++)
        m[i]=1;
    m[0]=m[1]=0;
    for(int i=2;i<=n;i++){
        if(m[i]){
            for(int j=i+i;j<=n;j+=i)
                m[j]=0;
            primes.push_back(i);
        }
    }
}

int getDigitSum(long n){
    int res=0;
    while(n){
        res+= n%10;
         n /= 10;
    }
    return res;
}

int factorize(long n){
    int res=0;
    long m = n;
    for(int i=0; ((primes[i]*primes[i]) <=n )&& ( i<primes.size()); i++){
        while(n%primes[i]==0){
            n /= primes[i];
            res+= getDigitSum(primes[i]);
        }
    }
    if(m==n) return -1;
    if(n!=1)
        res+=getDigitSum(n);
    return res;
}

int main(){
    sieve(32000);
    int t;
    scanf("%d",&t);
    long long n;

    while(t--){
        scanf("%ld",&n);
        long i=n+1;
        for(;;i++)
            if(getDigitSum(i)==factorize(i))
                    break;
        printf("%ld\n",i);
    }
    return 0;
}
