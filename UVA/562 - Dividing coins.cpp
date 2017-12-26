#include <bits/stdc++.h>

using namespace std;

int a[100];
int memo[100][50001];
int n;

int dp(int idx,int k){

    if(idx==n) return 0;

    if(memo[idx][k]!=-1) return memo[idx][k];

    if(k<a[idx])return dp(idx+1,k);

    return memo[idx][k] = max( dp(idx+1,k) , a[idx] + dp(idx+1, k-a[idx]) );
}

int main(){

    int t;
    scanf("%d",&t);


    while(t--){
        scanf("%d",&n);

        int acc = 0;
        for(int i=0;i<n;i++)
            scanf("%d",a+i),acc+=a[i];

        int k  = acc/2;

        memset(memo,-1,sizeof memo);
        int p1 = dp(0,k); int p2 =acc - p1;

        printf("%d\n",abs(p1-p2) );
    }
    return 0;
}
