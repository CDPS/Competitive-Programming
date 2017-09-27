#include <bits/stdc++.h>
 
using namespace std;
 
long long dp[31][31];
 
long long c(int n,int m){
    if(m==0 || m==n)
        return 1;
    if(dp[n][m]!=-1)return dp[n][m];
 
    return dp[n][m] = c(n-1,m-1) + c(n-1,m);
}
 
int main(){
 
    int t,caseno=1;
    scanf("%d",&t);
 
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        if(k>n){
            printf("Case %d: 0\n",caseno++);
        }
        else if(k==1){
            printf("Case %d: %lld\n",caseno++,n*n);
        }else{
            memset(dp,-1,sizeof dp);
 
            long long fac=1;
            for(int i=n-k+1;i<=n;i++)
                fac*=i;
 
            printf("Case %d: %lld\n",caseno++,fac*c(n,k));
        }
    }
 
    return 0;
}
