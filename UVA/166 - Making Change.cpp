#include <bits/stdc++.h>

using namespace std;

const int inf = 2000000;

int coins[6]= {5,10,20,50,100,200};
int a[6];

vector<int> memo, infmemo;

void shopper(){
    infmemo = vector<int> (3001,inf);
    infmemo[0]=0;
    for(int i=0;i<6;i++)
        for(int j=coins[i];j<=3000;j++)
            infmemo[j] = min(infmemo[j], 1 + infmemo[j-coins[i]]);
}

void buyer(int tam){
    memo = vector<int> (tam+1,inf);
    memo[0]=0;
    for(int i=0;i<6;i++)
        for(int j=coins[i];j<=tam;j++)
           for(int k=1;k<=a[i] && j>=coins[i]*k;k++)
                memo[j] = min( memo[j] , k + memo[j- coins[i]*k]);
}

int main(){
    double d;
    shopper();

    while(true){
        scanf("%d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]);

        if(a[0]==0 &&a[1]==0 &&a[2]==0 &&a[3]==0 &&a[4]==0 &&a[5]==0 ) break;

        scanf("%lf",&d);
        long m = (long)(d * 100 +0.5);

        int tam = (a[0]*coins[0])+(a[1]*coins[1])+(a[2]*coins[2])+(a[3]*coins[3])+(a[4]*coins[4])+(a[5]*coins[5]);

        buyer(tam);

        int ans=inf;
        for(int i=m;i<=tam;i++)
            ans= min(ans, memo[i]+infmemo[i-m]);

        printf("%3d\n",ans);
    }
    return 0;
}
