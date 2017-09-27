#include <bits/stdc++.h>

using namespace std;

const long m = 100000007;
int n,k;

int coins[50],amount[50];
long memo[1001];

long dp(int t){
    memset(memo,0,t);
    memo[0]=1;
    for(int i=0;i<n;i++){
        for(int j=coins[i];j<=t;j++){
            for(int k=1;k<=amount[i] && j>=k*coins[i];k++){
                memo[j] =( (memo[j]%m) + ( memo[j- (coins[i]*k) ]%m) )%m ;
            }
        }
    }

    return memo[t];
}
int main(){
    int t,caseno=1;
    scanf("%d",&t);

    while(t--){

        scanf("%d %d",&n,&k);

        for(int i=0;i<n;i++) scanf("%d",coins+i);

        for(int i=0;i<n;i++) scanf("%d",amount+i);

        printf("Case %d: %ld\n",caseno++,dp(k));
    }
    return 0;
}
