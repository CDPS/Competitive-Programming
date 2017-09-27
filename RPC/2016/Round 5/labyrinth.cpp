#include <bits/stdc++.h>

using namespace std;

char g[100][100][100];

int adx[4]={1,-1,0,0};
int ady[4]={0,0,1,-1};

int visit  [100][100][100];
long level [100][100][100];

int n,m,z;

struct node {
    int i;
    int j;
    int k;
    node(int a,int b, int c){
        i=a;
        j=b;
        k=c;
    }
};

bool isValid(int i,int j,int k){

    if( (i>=0 && i <n) && (j>=0 && j<m)&& (k>=0 && k<z) ){
        if(g[k][i][j]!='#')
            return true;
    }
    return false;
}

long bfs( node s){

    queue< node >q;
    q.push(s);

    visit[s.i][s.j][s.k]=1;
    level[s.i][s.j][s.k]=0;

    while(!q.empty()){

        int uz=q.front().i;
        int ux=q.front().j;
        int uy=q.front().k;

        q.pop();

        if(g[uz][ux][uy]=='E'){
            return level[uz][ux][uy];
        }

        if(g[uz][ux][uy]=='-'){

            if(isValid(ux,uy,uz+1)){

                if(!visit[uz+1][ux][uy] && g[uz+1][ux][uy]=='-' ){
                    level[uz+1][ux][uy]= 1l+ level[uz][ux][uy];
                    visit[uz+1][ux][uy]=1l;
                    q.push(node(uz+1,ux,uy));
                }
            }

            if(isValid(ux,uy,uz-1)){

                if(!visit[uz-1][ux][uy] && g[uz-1][ux][uy]=='-' ){
                    level[uz-1][ux][uy]= 1l+ level[uz][ux][uy];
                    visit[uz-1][ux][uy]=1;
                    q.push(node(uz-1,ux,uy));
                }
            }
        }

        for(int i=0;i<4;i++){
            int vx= ux+adx[i];
            int vy= uy+ady[i];
            int vz =uz;

            if(isValid(vx,vy,vz)){
                if(!visit[vz][vx][vy]){
                    level[vz][vx][vy]= 1l +level[uz][ux][uy];
                    visit[vz][vx][vy]=1;
                    q.push(node(vz,vx,vy));
                }
            }
        }
    }

    return -1;
}


int main(){

    while(true){
        scanf("%d %d %d",&n,&m,&z);

        if(n==0 && m==0 && z==0)
            break;
        node s = node(1,1,1);
        for(int i=0;i<z;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<m;k++){
                    scanf(" %c",&g[i][j][k]);
                    visit[i][j][k]=0;
                    level[i][j][k]=0;

                    if(g[i][j][k]=='S'){
                        s = node(i,j,k);
                        g[i][j][k]='.';
                    }
                }
            }
        }
        long res= bfs(s);
        printf("%ld\n",res);
    }

    return 0;
}
