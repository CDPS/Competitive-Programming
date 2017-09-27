#include <bits/stdc++.h>

using namespace std;

int coins [11]= {5,10,20,50,100,200,500,1000,2000,5000,10000};
long long memo[30001];

void dp(long n){
    memset(memo,0,sizeof memo); memo[0] =1;
    for(int i=0;i<11;i++)
        for(int j=coins[i];j<=n;j++)
            memo[j] = memo[j] + memo[j-coins[i]] ;
}

int main(){
    double n;
    dp(30000l);
    while(scanf("%lf",&n) ==1 && n ){
        long k = (long)(n * 100 +0.5);
        printf("%6.2f%17lld\n",n,memo[k]);
    }
    return 0;
}
