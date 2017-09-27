#include <bits/stdc++.h>

using namespace std;

bitset<1000001> m;
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


    sieve(1000000);
    int t;
    scanf("%d",&t);
    int l,h;

    while(t--){

        vector<int> frec(200,0);
        scanf("%d %d",&l,&h);

        int i=0;
        while(primes[i]<l)i++;

        i++;
        for(; primes[i]<=h && i<primes.size();i++)
            frec[ primes[i]- primes[i-1] ] ++;

        int maxX =-1;
        int champion=0;

        for(int i=0;i<frec.size();i++){
            if(maxX<frec[i]){
                maxX = frec[i];
                champion=i;
            }
        }

        if(maxX==0){
                printf("No jumping champion\n");
        }else{
            int f = 0;
            for(int i=0;i<frec.size();i++)
                if(frec[i]==maxX)
                    f++;
            if(f>1)
                printf("No jumping champion\n");
            else
                printf("The jumping champion is %d\n",champion);
        }
    }
    return 0;
}

