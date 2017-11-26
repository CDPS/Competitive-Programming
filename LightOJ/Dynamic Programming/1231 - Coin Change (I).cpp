#include <bits/stdc++.h>

using namespace std;

const long m = 100000007;
int n,k;

int coins[51],amount[51];
long memo[51][1001];

long dp(int t){
    for(int i=0;i<=t;i++)memo[0][i]=0;
    memo[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int l=0;l<=t;l++)memo[i][l]=memo[i-1][l];
        for(int j=1;j<=amount[i];j++)
            for(int k = t;k>=coins[i]*j;k--)
                memo[i][k] =((memo[i][k]%m) +(memo[i-1][ k-(j*coins[i]) ]%m ) )%m;
    }
    return memo[n][t];
}

int main(){
    int t,caseno=1;
    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",coins+i);
        for(int i=1;i<=n;i++) scanf("%d",amount+i);
        printf("Case %d: %ld\n",caseno++,dp(k));
    }
    return 0;
}
