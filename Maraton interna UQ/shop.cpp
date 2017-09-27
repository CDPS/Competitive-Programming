#include <bits/stdc++.h>

using namespace std;

int v[500];
int w[500];
int dp[501][501];
bool sol[501][501];

int minval=0;

int ksnp(int n,int we){

    for(int i=1;i<=n;i++){

        for(int j=1;j<=we;j++){

            int op1= dp[i-1][j-1];

            int op2= minval;

            if(w[i]<=w)
                op= v[i]+dp[i-1][j-w[i]];

            dp[i][j]= max(op1,op2);
            sol[i][j]= op1>op2;
        }
    }

}
int main(){


    int t;
    scanf("%d",&t);


    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",v+i);
            w[i]=1;
        }



    }
    return 0;
}
