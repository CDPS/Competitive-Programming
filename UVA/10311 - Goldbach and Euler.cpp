#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000000;
const int LMT =     10000;

int m[(MAX>>6)+1];

vector<int> primes;

long p1,p2, n;

#define isComp(n)  (m[n>>6]&(1<<((n>>1)&31)))
#define setComp(n) m[n>>6]|=(1<<((n>>1)&31))

void sieve() {
    for (int i = 3; i <= LMT; i += 2)
        if (!isComp(i))
            for (int j = i*i; j <= MAX; j += i+i)
                setComp(j);

    primes.push_back(2);
    for (int i=3; i <= MAX; i += 2)
        if (!isComp(i))
            primes.push_back(i);
}

bool isPrime(int n) {
    if (n < 2 || n % 2 == 0) return false;
    return ! isComp(n);
}

int binarySearch(long l, long h, long t){
    long m;
    while(l<h){
        m = (h+l)/2;
        if(primes[m]==t)
            return m;
        else if( primes[m]< t)
            l= m +1;
        else
            h= m-1;
    }
    return l;
}

bool scan(long n){
    if (n%2) {
        p1 = 2;
        return isPrime(n-p1);
    }
    int idx = binarySearch(0,primes.size(),n/2);
    for(int i= idx; i>=0;i--){
        p2 = n - primes[i];
        if(isPrime(p2) &&  p2 != primes[i]){
            p1 = min(p2, (long)primes[i]);
            return true;
        }
    }
    return false;
}

int main(){
    sieve();
    while(scanf("%ld",&n)==1){
        if(scan(n))
            printf("%ld is the sum of %d and %ld.\n", n, p1, n-p1);
        else printf("%ld is not the sum of two primes!\n", n);

    }
    return 0;
}
