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

    primes.push_back(2);
    for (int i=3; i <= MAX; i += 2)
        if (!isComp(i))
            primes.push_back(i);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    sieve();
    int t,n,x;
    cin >>t;
    while(t--){

        cin >> n;

        map<int,int> mp;
        for(int i=0;i<n;i++){
            cin >> x;
            for(int j=0; ((primes[j]*primes[j]) <=x )&&(j<primes.size());j++){
                while(x%primes[j]==0)
                    x /= primes[j], mp[ primes[j] ]++;
            }
            if(x!=1) mp[x]++;
        }

        bool ans = false;
        for(auto it = mp.begin(); it!=mp.end();it++)
            ans |=  !(it->second%n == 0);

        cout << (ans? "NO" : "YES" ) << "\n";
    }
    return 0;
}
