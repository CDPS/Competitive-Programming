#include <bits/stdc++.h>

using namespace std;

long long  m = 1073741824;

const int maxi =(100*100*100)+1;
int d[maxi];
bitset<1000001> mm;
vector<int> primes;

void sieve(){
    mm.reset();
    for (long long i = 3; i*i <maxi; i+=2)
        if (!mm[i])
            for (long long j = i*i; j <maxi ; j += i+i)
                    mm[j]=1;
    primes.push_back(2);
    for (int i=3; i < maxi; i += 2)
        if (!mm[i]) primes.push_back(i);
}

int factorize(int n){

    if(n==1)return 1;
    int res=1;

    for(int i=0;i<primes.size() && primes[i]*primes[i]<=n;i++){
        if(n%primes[i]==0){
            int exp =0;
            while(n%primes[i]==0){ n/=primes[i];exp++;}
            res= res*(exp+1);
        }
    }
    if(n!=1)res*=2;
    return res;
}

void divisor(){
    sieve();
    for(int i=1;i<maxi;i++) d[i] = factorize(i);
}

int main(){
    divisor();
    int a,b,c;
    cin >> a >> b >> c;

    long long res =0 ;
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
            for(int k=1;k<=c;k++)
                res=( (res%m) + (d[i*j*k]%m) )%m;
    cout << res <<"\n";
    return 0;
}
