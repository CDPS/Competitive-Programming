#include <bits/stdc++.h>

using namespace std;

const long long MAX =  1000000;
const long long  LMT =     1000;

int m[(MAX>>6)+1];

vector<long long> primes;

#define isComp(n)  (m[n>>6]&(1<<((n>>1)&31)))
#define setComp(n) m[n>>6]|=(1<<((n>>1)&31))

void sieve() {
    for (long long i = 3; i <= LMT; i += 2)
        if (!isComp(i))
            for (long long j = i*i; j <= MAX; j += i+i)
                setComp(j);

    primes.push_back(2ll);
    for (long long i=3; i <= MAX; i += 2)
        if (!isComp(i))
            primes.push_back(i);
}

bool isPrime(int n) {
    if(n==2) return true;
    if (n < 2 || n % 2 == 0) return false;
    return ! isComp(n);
}

int main(){
    sieve();
    int n;
    cin >> n;
    long long m;
    while(n--){
        cin >> m;
        long long s = sqrt(m);
        cout << (s*s==m && isPrime(s)? "YES" : "NO") << "\n";
    }
    return 0;
}
