#include <bits/stdc++.h>

using namespace std;

int c[16][16],memo[(1<<16)][16], match,n;

int dp(int mask,int idx){

    if(mask==match) return 0;

    if(memo[mask][idx]!=-1) return memo[mask][idx];

    int ans = -1;
    for(int i=0;i<n;i++){
        if( (mask&( 1 << i ))== 0)
            ans = max(ans, dp( mask | (1<<i) , idx +1) + c[idx][i] );
    }
    return memo[mask][idx]=ans;
}

int main(){

    int t,caseno=1;
    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&c[i][j]);

        match = (1<<(n))-1;
        memset(memo,-1,sizeof memo);
        printf("Case %d: %d\n",caseno++,dp(0,0));
    }
    return 0;
}
