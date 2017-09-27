#include <bits/stdc++.h>

using namespace std;

bitset<32769> m;
vector<int> primes;

void sieve(int n){
    m.set();
    for(int i = 0;i<=n;i++)
        m[i]=1;
    m[0]=m[1]=0;

    for(int i=2;i<=n;i++){
        if(m[i]){
            for(int j=i+i;j<=n;j+=i){
                m[j]=0;
            }
            primes.push_back(i);
        }
    }
}

int main(){

    sieve(32768);
    int n;
    while(true){
        scanf("%d",&n);
        if(n==0)
            break;
        int res=0;
        for(int i=0;primes[i]<=n/2;i++){
               int a = primes[i];
               int b = n-a;
               if(m[b]){
                    res++;
               }
        }

        printf("%d\n",res);

    }
    return 0;
}
