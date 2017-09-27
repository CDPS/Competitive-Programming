
#include <bits/stdc++.h>

using namespace std;


int g[3][3];
int v[3][3];

int xs [4] = {1,-1,0,0};
int ys [4] = {0,0,1,-1};

bool isValid(int x,int y){
    if(x>=0 && x<3 && y>=0 && y<3)
        return true;
    return false;
}

int main(){

    memset(g , 0, sizeof g);
    memset(v, 0, sizeof v);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&g[i][j]);
         }
    }


    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(g[i][j]==0) continue;
            v[i][j]+= g[i][j];

            for(int k=0;k<4;k++){
                int vx = i + xs[k];
                int vy = j + ys[k];

                if(isValid(vx,vy)){
                    v[vx][vy]+= g[i][j];
                }
            }
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(v[i][j]%2)printf("0");
            else printf("1");
        }
        printf("\n");
    }

    return 0;
}
