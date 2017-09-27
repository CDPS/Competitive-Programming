#include <bits/stdc++.h>

using namespace std;


const int MAX = 100000000;
const int LMT =     10000;

int m[(MAX>>6)+1];

vector<long long> primes;

#define isComp(n)  (m[n>>6]&(1<<((n>>1)&31)))
#define setComp(n) m[n>>6]|=(1<<((n>>1)&31))

void sieve() {
    for (int i = 3; i <= LMT; i += 2)
        if (!isComp(i))
            for (int j = i*i; j <= MAX; j += i+i)
                setComp(j);

    primes.push_back(2);
    for (long long i=3; i <= MAX; i += 2)
        if (!isComp(i))
            primes.push_back(i);
}

long long getPrime(long long n) {

    long long r =-1;
    if(n<=1) return r;
    int c=0;

    for(int i=0;i< primes.size() && primes[i]*primes[i] <= n ;i++){
        if(n%primes[i]==0){
            c++;
            r=primes[i]; while(n%r==0){n/=r;}
        }
    }
    if(n!=1 && r!=-1){r=n; c++;}
    if(c==1)return -1;
    return r;
}

int main(){
    sieve();

    long long n;

    while(scanf("%lld",&n) && n){
            printf("%lld\n",getPrime( abs(n)) );
    }
    return 0;
}
