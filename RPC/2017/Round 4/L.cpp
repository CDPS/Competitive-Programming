#include <bits/stdc++.h>

using namespace std;


const int MAX = 100000;
const int LMT =   1000;

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

void factorize(long long n){


    long long res=1,m  = n,res2=n;

    for(int i=0;i<primes.size() && primes[i]*primes[i]<=n;i++){
        if(n%primes[i]==0){
            int exp =0;

            while(n%primes[i]==0){ n/=primes[i];exp++;}

            res2*=(primes[i]-1); res2/=primes[i];

            res*=(pow(primes[i],exp+1) -1);
            res/=primes[i]-1;
        }
    }

    if(n!=1){res*=(pow(n,2)-1);res/=n-1; res2*=(n-1); res2/=n;}

    res-=m+1;
    printf("%lld %lld\n",res,res2);
    long long sum = ( (m*(m-1))/2) - res;
    printf("%lld %.4lf\n",res2,double(sum)/double(m));
}


int main(){

    sieve();
    int t;

    scanf("%d",&t);

    long long n;

    while(t--){
        scanf("%lld",&n);
        factorize(n);
    }
    return 0;
}
