#include <bits/stdc++.h>

using namespace std;

const int MAX =  1000000;
const int LMT =     1000;

int m[(MAX>>6)+1];

vector<long long> primes;
vector<long long> almostPrimes;

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
            primes.push_back((long long)i);
}

void fillAlmostPrime(){
    for (int i = 0; i < primes.size(); i++){
        for (long long j= primes[i]*primes[i]; j<= 1000000000000ll; j*=primes[i]){
                    almostPrimes.push_back(j);
        }
    }
}

int main(){
    sieve();
    fillAlmostPrime();
    sort(almostPrimes.begin(),almostPrimes.end());

    int n;
    scanf("%d",&n);
    long long l,h;
    while(n--){
        scanf("%lld %lld",&l,&h);
        int i = int(lower_bound( almostPrimes.begin(), almostPrimes.end(), l) - almostPrimes.begin());
        int j = int(lower_bound( almostPrimes.begin(), almostPrimes.end(), h) - almostPrimes.begin());
        printf("%d\n",j-i);
    }
    return 0;
}
