#include <bits/stdc++.h>

using namespace std;

int n,a[10][1000],memo[10][1000];

int oo = 1000000000;

int dp(int i, int j){

    if(j== n && i!=0) return oo;
    if(j== n && i==0) return 0;
    if(memo[i][j]!=-1) return memo[i][j];

    int ans  = oo;

    if(i+1<=9) ans = min(ans, 60 + a[i][j] + dp(i+1,j+1) );
    if(i-1>=0) ans = min(ans, 20 + a[i][j] + dp(i-1,j+1) );
               ans = min(ans, 30 + a[i][j] + dp(i,j+1) );
    return memo[i][j] = ans;
}

int main(){

    int t;
    scanf("%d",&t);

    while(t--){
        scanf("%d\n",&n); n/=100;
        for(int i=9;i>=0;i--)
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]), a[i][j]*=-1,memo[i][j]=-1;
        printf("%d\n\n", dp(0,0) );
    }
    return 0;
}
