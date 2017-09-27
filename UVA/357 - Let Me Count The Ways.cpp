#include <bits/stdc++.h>

using namespace std;

long long memo[30001];
int coins[5]={1,5,10,25,50};
void dp(){
    memo[0]=1;
    for(int i=0;i<5;i++){
        for(int j=coins[i];j<=30000;j++){
            memo[j]= memo[j] + memo[ j-coins[i]];
        }
    }
}

int main(){
    dp();
    int n;
    while(scanf("%d",&n)==1)
        if(memo[n]==1)
         printf("There is only 1 way to produce %d cents change.\n",n);
        else
        printf("There are %lld ways to produce %d cents change.\n",memo[n],n);
    return 0;
}
