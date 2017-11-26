#include <bits/stdc++.h>

using namespace std;

int v[1000],w[1000];
int memo[1000][31];

int n,m,c;

int dp(int idx,int k){

    if(idx==n) return 0;

    if(memo[idx][k]!=-1) return memo[idx][k];

    if(w[idx]>k) return dp(idx+1,k);

    return memo[idx][k] = max(  dp(idx+1,k), v[idx] + dp(idx+1, k - w[idx] ) );
}

int main(){

    int t;
    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);

        for(int i=0;i<n;i++)
            scanf("%d %d",v+i,w+i);

        memset(memo,-1,sizeof memo);

        scanf("%d",&m);
        int ans = 0;
        while(m--){
            scanf("%d",&c);
            ans = ans + dp(0,c);
        }
        printf("%d\n",ans);
    }
    return 0;
}
