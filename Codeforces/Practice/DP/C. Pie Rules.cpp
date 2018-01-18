#include <bits/stdc++.h>

using namespace std;

int a[50],n;
int memo[50][2];

int dp(int idx, bool f){

    if(idx == n ) return 0;

    if(memo[idx][f]!=-1) return memo[idx][f];

    return memo[idx][f] = (f)? max( a[idx] + dp(idx+1,!f), dp(idx+1,f) ) : min( a[idx] +dp(idx+1,f),dp(idx+1,!f) );
}

int main(){

    scanf("%d",&n);

    memset(memo,-1, sizeof memo);
    int acc =0;
    for(int  i=0;i<n;i++)
        scanf("%d",a + i), acc = acc + a[i];
    int ans = dp(0,1);
    printf("%d %d\n",acc- ans,ans);
    return 0;
}
