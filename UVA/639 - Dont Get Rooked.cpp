#include <bits/stdc++.h>

using namespace std;

char g[4][4];

int n;

bool isValid(int x, int y){
    for(int i=x+1; i < n && g[i][y]!='X';i++)
        if(g[i][y]=='1') return false;
     for(int i=x-1; i >= 0 && g[i][y]!='X';i--)
        if(g[i][y]=='1') return false;
    for(int i=y+1; i < n && g[x][i]!='X';i++)
        if(g[x][i]=='1') return false;
     for(int i=y-1; i >= 0 && g[x][i]!='X';i--)
        if(g[x][i]=='1') return false;
    return true;
}

int ans;

void backtrack(int rook){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]=='.' && isValid(i,j)){
                g[i][j]='1';
                backtrack(rook+1);
                g[i][j]='.';
            }
        }
    }

    ans = max(ans,rook);
}

int main(){

    while( scanf("%d",&n) && n!=0){

        for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
             scanf(" %c",&g[i][j]);
        ans=0;
        backtrack(0);
        printf("%d\n",ans);
    }
    return 0;
}
