#include <bits/stdc++.h>

using namespace std;

char g[200][200];

bool visit[200][200];
bool visitF[200][200];

int level[200][200];
int levelF[200][200];


int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};

int n,m;

const int INF = 2000000000;

queue< pair<int,int> >fire;


bool isValid(int i,int j){

    if( (i>=0 && i <n) && (j>=0 && j<m)){

        if(g[i][j]!='#')
            return true;
    }
    return false;
}

void bfs( pair <int,int> s){

    queue< pair<int,int> >q;
    q.push(s);

    visit[s.first][s.second]=1;
    level[s.first][s.second]=0;

    while(!q.empty()){

        int ux=q.front().first;
        int uy=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){

            int vx= ux+x[i];
            int vy= uy+y[i];

            if( isValid(vx,vy)){

                if(!visit[vx][vy]){

                    level[vx][vy]= 1+level[ux][uy];
                    visit[vx][vy]=1;
                    q.push(make_pair(vx,vy));
                }
            }
        }
    }
}


void bfsf( queue< pair<int,int> > q){

    while(!q.empty()){

        int ux=q.front().first;
        int uy=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){

            int vx= ux+x[i];
            int vy= uy+y[i];

            if( isValid(vx,vy)){

                if(!visitF[vx][vy]){

                    levelF[vx][vy]= 1+levelF[ux][uy];
                    visitF[vx][vy]=1;
                    q.push(make_pair(vx,vy));
                }
            }
        }
    }
}

int main(){

    int t,caseno=1;
    scanf("%d",&t);


    while(t--){

        scanf("%d %d",&n,&m);

        pair<int,int> s;

        fire= queue< pair<int,int> >();

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){
                visit[i][j]=0;
                level[i][j]=INF;

                visitF[i][j]=0;
                levelF[i][j]=INF;

                scanf(" %c",&g[i][j]);

                if(g[i][j]=='F'){
                   fire.push(make_pair(i,j));
                   levelF[i][j]=0;
                   visitF[i][j]=1;
                }

                if(g[i][j]=='J'){
                        s = make_pair(i,j);
                        g[i][j]='.';
                }
            }
        }

        bfs(s);
        bfsf(fire);

        int res=INF;

       for(int i=0;i<m;i++){
            if(g[0][i]=='.'){
                if(level[0][i]<levelF[0][i]){
                   res= min(res,level[0][i]);
                }
            }

            if(g[n-1][i]=='.'){
                if(level[n-1][i]<levelF[n-1][i]){
                    res=min(res,level[n-1][i]);
                }
            }
        }


        for(int i=0;i<n;i++){
            if(g[i][0]=='.'){
                if(level[i][0]<levelF[i][0]){
                   res= min(res,level[i][0]);
                }
            }

            if(g[i][m-1]=='.'){
                if(level[i][m-1]<levelF[i][m-1]){
                    res=min(res,level[i][m-1]);
                }
            }
        }

        if(res!=INF){
            printf("Case %d: %d\n",caseno++, (res+1) );
        }else{
            printf("Case %d: IMPOSSIBLE\n",caseno++);
        }


    }
    return 0;
}
