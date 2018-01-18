#include <bits/stdc++.h>

using namespace std;

int oo=1000000000;
int memo[10][100],g[10][100],path[10][100];
int n,m,ad[3]={-1,0,1};

void dp(){

    for(int j=m-2;j>=0;j--){
        for(int i=0;i<n;i++){
            for(int k=0;k<3;k++){
                int vx =  (ad[k]<0)? ( (i%n) + (ad[k]%n) + n )%n :( (i%n) + (ad[k]%n) )%n;
                if( memo[vx][j+1] + g[i][j] < memo[i][j] || (memo[vx][j+1] + g[i][j] == memo[i][j] && vx < path[i][j]) ){
                    memo[i][j]= memo[vx][j+1] + g[i][j];
                    path[i][j]= vx;
                }
            }
        }
    }

    int ans=oo,idx = 0;
    for(int i=0;i<n;i++)
        if(memo[i][0]<ans)
            ans = memo[i][0],idx = i;

    printf("%d",idx+1);
    for(int i=0;i<m-1;i++) idx = path[idx][i], printf(" %d",idx+1);
    printf("\n%d\n",ans);
}

int main(){

    while(scanf("%d %d",&n,&m)==2){

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                path[i][j]=-1, memo[i][j]=oo, scanf("%d",&g[i][j]);

        for(int i=0;i<n;i++) memo[i][m-1] = g[i][m-1];
        dp();
    }
    return 0;
}

