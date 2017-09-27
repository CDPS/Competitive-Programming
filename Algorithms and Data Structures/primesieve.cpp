#include <bits/stdc++.h>

using namespace std;

const int MAX =  10000000;
const int LMT =     10000;

int m[(MAX>>6)+1];

vector<int> primes;

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
    if(n==2) return true;
    if (n < 2 || n % 2 == 0) return false;
    return ! isComp(n);
}
