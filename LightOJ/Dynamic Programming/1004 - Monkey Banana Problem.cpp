#include <bits/stdc++.h>
 
using namespace std;
 
int g[199][100];
int dis[199][100];
int n;
 
int dp(int i,int j,int e){
 
    if(i==2*n-2){
        return g[i][0];
    }
 
    if(i<n-1){
 
        if(dis[i+1][j]==-1)
        {
            dis[i+1][j]= dp(i+1,j,e);
        }
 
        if(dis[i+1][j+1]==-1)
        {
            dis[i+1][j+1]= dp(i+1,j+1,e);
        }
 
        return max(dis[i+1][j], dis[i+1][j+1]) + g[i][j];
    }
 
    if(j==0){
        if(dis[i][j]==-1){
            dis[i][j]= dp(i+1,0,e-1)+g[i][j];
        }
        return dis[i][j];
    }
 
    if(j==e-1){
 
        if(dis[i][j]==-1){
            dis[i][j]= g[i][j] + dp(i+1,j-1,e-1) ;
        }
        return dis[i][j];
    }
 
    if(dis[i+1][j]==-1)
    {
        dis[i+1][j]= dp(i+1,j,e-1);
    }
 
    if(dis[i+1][j-1]==-1)
    {
        dis[i+1][j-1]= dp(i+1,j-1,e-1);
    }
 
    return max(dis[i+1][j],dis[i+1][j-1]) + g[i][j];
 
}
 
int main(){
    int t,caseno=1;
 
    scanf("%d",&t);
    while(t--){
 
 
        scanf("%d",&n);
 
        int i=0;
 
        for(;i<n;i++){
            for(int j=0;j<=i;j++){
                scanf("%d",&g[i][j]);
            }
        }
 
        int j=i-1;
        for(int k=i;k< (2*n)-1;k++){
            for(int l=0;l<j;l++){
                scanf("%d",&g[k][l]);
            }
            j--;
        }
 
        memset(dis, -1, sizeof(dis[0][0]) *199 *100);
 
        int res= dp(0,0,n);
        printf("Case %d: %d\n",caseno++,res);
    }
 
 
    return 0;
}
