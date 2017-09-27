#include <bits/stdc++.h>

using namespace std;

const int MAX =  20000000;
const int LMT =      9900;

int m[(MAX>>6)+1];

vector< pair<int,int> >primes;

#define isComp(n)  (m[n>>6]&(1<<((n>>1)&31)))
#define setComp(n) m[n>>6]|=(1<<((n>>1)&31))

void sieve() {
    for (int i = 3; i <= LMT; i += 2)
        if (!isComp(i))
            for (int j = i*i; j <= MAX; j += i+i)
                setComp(j);

    primes.push_back(make_pair(3,5));
    for(int i=7; i <= MAX; i += 2)
        if ( !isComp(i) && !isComp(i-2) )
            primes.push_back(make_pair(i-2,i));
}

bool isPrime(int n) {
    if (n < 2 || n % 2 == 0) return false;
    return ! isComp(n);
}

int main(){
    sieve();
    int i;
    pair<int,int> r;
    while(scanf("%d",&i)==1){
        r = primes[i-1];
        printf("(%d, %d)\n",r.first,r.second);
    }
    return 0;
}
