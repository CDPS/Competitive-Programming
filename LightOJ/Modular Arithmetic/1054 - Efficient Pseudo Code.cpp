#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;

bitset< 700001 > m;
vector<long long> primes;

void sieve(long long n){
    m.reset();
    for (long long i = 3; i*i <=n; i+=2)
        if (!m[i])
            for (long long j = i*i; j <=n ; j += i+i)
                    m[j]=1;
    primes.push_back(2ll);
    for (long long i=3; i <= n; i += 2)
        if (!m[i])
            primes.push_back(i);
}

long long  mul(unsigned long long  a, unsigned long long  b) {
    unsigned  ret = 0;
    for (a %= mod, b %= mod; b != 0; b >>= 1, a <<= 1, a = a >= mod ? a - mod : a) {
        if (b&1) {
            ret += a;
            if (ret >= mod)    ret -= mod;
        }
    }
    return ret;
}

long long powm(long long a,long long b){
    long long ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

vector<pair<long long,long long> > factorize(long long n){

    vector<pair<long long,long long> > ans;

    for(int i=0;i<primes.size() && primes[i]*primes[i] <= n; i++){
        if(n%primes[i]==0){
            long long exp =0;
            while(n%primes[i]==0) n/=primes[i],exp++;
            ans.push_back(make_pair(primes[i],exp));
        }
    }
    if(n!=1)ans.push_back(make_pair(n,1));
    return ans;
}

long long getAns(long long n, long long m){

    vector< pair<long long, long long> > f = factorize(n);

    long long ans=1;
    for(int i=0;i<f.size();i++){

        long long v = ( powm(f[i].first, (f[i].second *m)+1 )  - 1  + mod)%mod;
        v =  ( (v%mod) * (powm(f[i].first -1 , mod-2)%mod) )%mod;
        ans=( (ans%mod)*(v%mod))%mod;
    }
    return ans;
}

int main(){
    sieve(700000);
    int t,caseno=1;
    scanf("%d",&t);

    long long n,p;
    while(t--){
        scanf("%lld %lld",&n,&p);
        printf("Case %d: %lld\n",caseno++,getAns(n,p));
    }
}
