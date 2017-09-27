#include <bits/stdc++.h>

using namespace std;

bitset<46345> m;
vector<long> primes;

void sieve(int n){
    m.set();
    for(int i=2;i<=n;i++)
        m[i]=1;
    m[0]=m[1]=0;
    for(long i=2;i<=n;i++){
        if(m[i]){
            for(long j=i+i;j<=n;j+=i)
                m[j]=0;
            primes.push_back(i);
        }
    }
}

bool isPrime(long n){
    if(n==1)
        return false;
    for(int i=0; (primes[i]*primes[i]<=n) && i<primes.size();i++)
        if(n%primes[i]==0)
            return false;
    return true;
}

int main(){

    sieve(46344);
    long l,h;
    int eprimes,bprime;
    int c1, c2,d1,d2;
    int minDis, maxDis;

    while(scanf("%ld %ld",&l,&h)==2){
        if(!(l&2)&&l!=2)
            l++;
        eprimes=0, bprime=0;
        minDis=10000, maxDis=-1;

        for(long i=l;i<=h;i= (i==2)? i+1: i+2){
            if(isPrime(i)){
                if(eprimes>=1){
                    if( i - bprime < minDis){
                        c1 = i;
                        c2 = bprime;
                        minDis= i-bprime;
                    }
                    if( i - bprime > maxDis){
                        d1 = i;
                        d2 = bprime;
                        maxDis=i-bprime;
                    }
                    bprime=i;
                    eprimes++;
                }else{
                    bprime=i;
                    eprimes++;
                }
            }
        }

        if(eprimes>1)
            printf("%d,%d are closest, %d,%d are most distant.\n",c2,c1,d2,d1);
        else
            printf("There are no adjacent primes.\n");
    }
    return 0;
}
