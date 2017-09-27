#include <bits/stdc++.h>

using namespace std;

long long memo[101][101];

long long dp(int n, int k){
    if(k==0 || k==n)
        return 1ll;
    if(memo[n][k]!=-1) return memo[n][k];
    return  memo[n][k]= dp(n-1,k-1) + dp(n-1,k);
}

int main(){
    int n,m;
    while(true){
        scanf("%d %d",&n,&m);
        if(n==0 && m==0) break;
        memset(memo,-1,sizeof memo);
        printf("%d things taken %d at a time is %lld exactly.\n",n,m,dp(n,m));
    }
    return 0;
}
