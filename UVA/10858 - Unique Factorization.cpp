#include <bits/stdc++.h>

using namespace std;

vector<int> factorize(int n){
    vector<int> ans;
    for(int i=0;i< primes.size() && primes[i]*primes[i]<=n;i++){
        if(n%primes[i]==0)
            while(n%primes[i]==0)
                ans.push_back(primes[i]), n/=primes[i];
    }
    if(n!=1) ans.push_back(n);
    return ans;
}

int main(){

    sieve();

    int n;
    while(cin >> n && n){

        vector<int> factors = factorize(n);

        for(int i=0;i<factors.size();i++)
            cout << factors[i] << "\n";
        cout << "\n";
    }

    return 0;
}
