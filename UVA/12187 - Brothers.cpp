#include <bits/stdc++.h>

using namespace std;

int h,n,m,k;
int g[100][100], temp[100][100];
int xs[4]={1,-1,0,0};
int ys[4]={0,0,1,-1,};


bool isValid(int x, int y, int val){
    return x >=0 && x<n && y>=0 && y <m && g[x][y]== (val + 1)%h;
}

void process(){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                int vx = i + xs[k], vy = j + ys[k];
                if(isValid(vx,vy,g[i][j])){
                    temp[vx][vy]=g[i][j];
                }
            }
        }
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            g[i][j] = temp[i][j] ;
}

int main(){

    while(cin >> h >> n >> m >> k){

        if(h==0 && n ==0 && m==0 && k==0)
            break;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin >> g[i][j], temp[i][j] = g[i][j];

        while(k--)
            process();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0) cout << g[i][j];
                else cout << " " << g[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
