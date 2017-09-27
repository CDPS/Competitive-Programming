#include <bits/stdc++.h>

using namespace std;

long long memo[7490];
int coins[4] = {5,10,25,50};

void dp(int n){
    for(int i=0;i<=n;i++) memo[i]=1;
    for(int i=0;i<4;i++)
        for(int j=coins[i];j<=n;j++)
            memo[j]= memo[j] + memo[ j - coins[i] ];
}

int main(){
    dp(7489);
    int n;
    while(scanf("%d",&n)==1)
        printf("%lld\n",memo[n]);
    return 0;
}
