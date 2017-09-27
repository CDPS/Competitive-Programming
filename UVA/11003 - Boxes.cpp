#include <bits/stdc++.h>

using namespace std;

int n;
long a[1000][2], memo[1000][5001];

int const inf = 5000;

long dp(int idx, int cap){

    if(idx==n)
        return 0;

    if(memo[idx][cap]!=-1)  return memo[idx][cap];

    if(cap < a[idx][0])
        return dp(idx+1,cap);

    return memo[idx][cap] = max( dp(idx+1,cap), dp(idx+1, min(cap-a[idx][0],a[idx][1])) +1 );
}

int main(){

    int w,c;
    while(scanf("%d",&n) && n){
        for(int i=0;i<n;i++)
            scanf("%ld %ld", &a[i][0] , &a[i][1]);
        memset(memo,-1, sizeof memo);
        printf("%ld\n",dp(0,inf));
    }
    return 0;
}
