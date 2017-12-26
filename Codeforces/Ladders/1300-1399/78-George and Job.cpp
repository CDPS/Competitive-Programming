#include <bits/stdc++.h>

using namespace std;

long long a   [5001];
long long acc [5001];
long long memo[5001][5001];
int n,m,k;

long long dp(int idx,int w){

    if(idx==n+1)  return 0;

    if(w==k)      return 0;

    if(memo[idx][w]!=-1) return memo[idx][w];

    if(idx+m>n+1) return 0;

    return memo[idx][w] = max( dp(idx+1,w), (acc[idx+m-1]-acc[idx-1]) + dp(idx+m,w+1)  );
}

int main(){

    scanf("%d %d %d",&n,&m,&k);

    a[0] = acc[0]=0;
    for(int i=1;i<=n;i++)
        scanf("%I64d",a+i),acc[i]=acc[i-1] +a[i];

    memset(memo,-1,sizeof memo);
    printf("%I64d",dp(1,0));
    return 0;
}
