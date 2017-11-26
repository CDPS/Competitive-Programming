#include <bits/stdc++.h>

using namespace std;

int n,m;

int g[10][10];

void processV(int x){
    for(int i=0;i<n;i++)
        if(g[i][x]==0)g[i][x]=1;
}
void processH(int y){
    for(int i=0;i<m;i++)
        if(g[y][i]==0)g[y][i]=1;
}

int checkH(int j){
    int r=0;
    for(int i=0;i<m;i++)
        if(!g[j][i])r++;
        else if(g[j][i]==2)return 0;
    return r;
}

int checkV(int j){
    int r=0;
    for(int i=0;i<n;i++)
        if(g[i][j]==0)r++;
        else if(g[i][j]==2)return 0;
    return r;
}

int main(){
    scanf("%d %d",&n,&m);

    char c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %c",&c);
            g[i][j]=(c=='S')?2:0;
        }
    }

    int res=0;
    for(int i=0;i<m;i++){
        int r = checkV(i);
        if(r>=1){
            res+=r;
            processV(i);
        }
    }

    for(int i=0;i<n;i++){
        int r = checkH(i);
        if(r>=1){
            res+=r;
            processH(i);
        }
    }

    printf("%d\n",res);
    return 0;
}
