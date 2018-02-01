#include <bits/stdc++.h>

using namespace std;

int a[100],b[100],n,m;

int memo[100][100];

int dp(int idx,int idy){

    if(idx == n || idy == m) return 0;

    if(memo[idx][idy]!=-1)  return memo[idx][idy];

    return memo[idx][idy]= (a[idx]==b[idy])? 1 + dp(idx+1,idy+1) : max(  dp(idx+1,idy) , dp(idx,idy+1) );
}

int main(){

    int caseno=1;
    while(scanf("%d %d",&n,&m) && !(n==0 && m==0) ){

        for(int i=0;i<n;i++) scanf("%d",a+i);
        for(int i=0;i<m;i++) scanf("%d",b+i);

        memset(memo,-1, sizeof memo);
        printf("Twin Towers #%d\n",caseno++);
        printf("Number of Tiles : %d\n\n",dp(0,0));
    }
    return 0;
}
