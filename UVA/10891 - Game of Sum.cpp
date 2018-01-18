#include <bits/stdc++.h>

using namespace std;

int oo = -1000000000;
int a[100],n;
int memo[100][100][2];

int dp(int i,int j, bool f) {

    if(i>j || i==j &&!f) return 0;
    if(i==j && f)        return a[i];

    if(memo[i][j][f]!=-1) return memo[i][j][f];

    int ans= (f)? oo : oo*-1;

    if(f){
        int acc1 = 0, acc2 =0 ;
        for(int k = i,l=j; k<=j;k++,l--){
            acc1 = acc1 + a[k]; acc2 = acc2 + a[l];
            ans = max( ans, max( acc1 + dp(k+1,j,!f) , acc2 + dp(i,l-1,!f)) );
        }
    }else{
        for(int k = i,l=j; k<=j;k++,l--){
            ans = min( ans , min(  dp(k+1,j,!f), dp(i,l-1,!f)) );
        }
    }
    return memo[i][j][f] = ans;
}

int main(){

    while(scanf("%d",&n) && n){
        memset(memo,-1,sizeof memo);
        int acc =0 ;
        for(int i=0;i<n;i++) scanf("%d",a+i), acc = acc + a[i];
        int ans = dp(0,n-1,1);
        printf("%d\n", ans - (acc-ans)  );
    }
    return 0;
}
