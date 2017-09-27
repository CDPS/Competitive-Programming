#include <bits/stdc++.h>

using namespace std;

const string endline = "\n";

bitset<1000001> m;
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

long long factorize(long long n){

    if(n==1)return 1;
    long long res=1;

    for(int i=0;i<primes.size() && primes[i]*primes[i]<=n;i++){
        if(n%primes[i]==0){
            int exp =0;
            while(n%primes[i]==0){ n/=primes[i];exp++;}
            res*=(pow(primes[i],exp+1) -1);
            res/=primes[i]-1;
        }
    }
    if(n!=1){res*=(pow(n,2)-1);res/=n-1;}
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long t, n, ans;
    sieve(1000000);
    cin >> t;

    while(t--) {
        cin >> n;
        ans = factorize(n) - n;
        if(ans == n)
            cout << "perfect" << endline;
        else if(ans < n)
            cout << "deficient" << endline;
        else if(ans > n)
            cout << "abundant" << endline;
    }
    return 0;
}
