#include <bits/stdc++.h>

using namespace std;

char g[500][500];

int adx[4]={1,-1,0,0};
int ady[4]={0,0,1,-1};

bool v[500][500];

map <pair <int,int>, int> ex;

int bfs(int x,int y,int n,int m){

    queue< pair<int,int> > q;
    vector<pair<int,int> > e;
    q.push( make_pair(x,y) ) ;

    v[x][y]=1;

    e.push_back(make_pair(x,y));
    int res=0;

    while(!q.empty()){

        int ux= q.front().first;
        int uy= q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int vx= ux+adx[i];
            int vy= uy+ady[i];
            if( (vx>=0 && vx<n)  && (vy>=0 && vy<m)){

                if(g[vx][vy]!='#' && !v[vx][vy] ){
                    q.push(make_pair(vx,vy));
                    v[vx][vy]=1;
                    e.push_back(make_pair(vx,vy));
                    if(g[vx][vy]=='C')
                        res++;
                }
            }
        }
    }

    for(int i=0;i<e.size();i++){
        ex[e[i]]=res;
    }

    return res;
}

int main(){

    int t,caseno=1,m,n,q;

    scanf("%d",&t);

    while(t--){
        scanf("%d %d %d",&n,&m,&q);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf(" %c",&g[i][j]);
                v[i][j]=0;
            }
        }

        int x,y;
        printf("Case %d:\n",caseno++);
        while(q--){
            scanf("%d %d",&x,&y);
            int res;

            if(v[x-1][y-1]){
                res = ex[make_pair(x-1,y-1)];
            }
            else{
                res = bfs(x-1,y-1,n,m);
            }

            printf("%d\n",res);
        }
        ex.clear();
    }

    return 0;
}
