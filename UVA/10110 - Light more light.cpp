#include <bits/stdc++.h>

using namespace std;

bitset<65541> m;
vector<long long> primes;

void sieve(int n){
   m.reset();m.flip();
   m[0] = m[1] =0;
   for (int i = 3; i*i <= n; i += 2)
        if (m[i])
            for (int j = i*i; j <= n; j += i+i)
                m[j]=0;
    primes.push_back(2);
    for (int i=3; i <= n; i += 2)
        if (m[i])
            primes.push_back(i);
}

long divs(long long n){
    long res = 1,ex;
    for(int i=0;i<primes.size() && primes[i]*primes[i]<=n;i++){
        if(n%primes[i]==0){
            ex =0;
            while(n%primes[i]==0)ex++,n/=primes[i];
            res*=(ex+1);
        }
    }
    if(n!=1)res*=2;
    return res;
}

int main(){
    sieve(65540);
    long long n;
    while(cin >> n && n){
        cout << (divs(n)%2? "yes" : "no") << "\n";
    }
    return 0;
}
