#include <bits/stdc++.h>

using namespace std;

const int MAX =  1000000;
const int LMT =     1000;

int m[(MAX>>6)+1];

vector<int> primes;

#define isComp(n)  (m[n>>6]&(1<<((n>>1)&31)))
#define setComp(n) m[n>>6]|=(1<<((n>>1)&31))

void sieve() {
    for (int i = 3; i <= LMT; i += 2)
        if (!isComp(i))
            for (int j = i*i; j <= MAX; j += i+i)
                setComp(j);

    primes.push_back(2ll);
    for (int i=3; i <= MAX; i += 2)
        if (!isComp(i))
            primes.push_back(i);
}

int factorize(int n){
    int res=0;
    for(int i=0;i< primes.size() && primes[i]*primes[i]<=n;i++){
        if(n%primes[i]==0){
            res++;
            while(n%primes[i]==0){
                n/=primes[i];
            }
        }
    }
    if(n!=1)res++;
    return res;
}

int main(){
    sieve();
    int n;
    while(scanf("%d",&n) && n){
        printf("%d : %d\n",n,factorize(n));
    }
    return 0;
}
