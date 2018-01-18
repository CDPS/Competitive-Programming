#include <bits/stdc++.h>

using namespace std;

int l,n,m,u,memo[20][201];
vector<int> g[100];

int dp(int idx,int acc){

    if(acc > l) return -1;

    if(idx==n)  return acc;

    if(memo[idx][acc]!=-1) return memo[idx][acc];

    int ans = -1;
    for(int i=0;i<g[idx].size();i++)
        ans = max( ans, dp(idx+1,acc + g[idx][i] ) );

    return memo[idx][acc] = ans;
}

int main(){

    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d",&l,&n);

        for(int i=0;i<n;i++){
            scanf("%d",&m);
            for(int j=0;j<m;j++)
                scanf("%d",&u),g[i].push_back(u);
        }

        memset(memo,-1,sizeof memo );
        int ans = dp(0,0);
        if(ans == -1) printf("no solution\n");
        else printf("%d\n",ans);

        for(int i=0;i<n;i++) g[i].clear();
    }
    return 0;
}
