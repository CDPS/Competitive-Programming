#include <bits/stdc++.h>

using namespace std;

long long memo[10001];

void dp(){
    memset(memo,0,sizeof memo);
    memo[0]=1;
    for(int i=1;i<=21;i++){
        int r = i*i*i;
        for(int j=r;j<10001;j++)
            memo[j] = memo[j] + memo[j-r];
    }
}

int main(){
    dp();
    int n;
    while(scanf("%d",&n)==1)
        printf("%lld\n",memo[n]);
    return 0;
}
