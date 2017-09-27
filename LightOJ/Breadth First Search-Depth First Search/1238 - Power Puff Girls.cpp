#include <bits/stdc++.h>


using namespace std;

char g[20][20];

bool v[20][20];
int l[20][20];


int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};

 int n,m;

bool isValid(int i,int j){

    if( (i>=0 && i<n) && (j>=0 && j<m) ){

        if(g[i][j]=='.'){
            return 1;
        }
    }
    return 0;
}


int bfs(int i,int j, int it, int jt){

    queue< pair<int,int> > q;

    q.push(make_pair(i,j));

    v[i][j]=1;
    l[i][j]=0;

    while(!q.empty()){

        int ux = q.front().first;
        int uy= q.front().second;

        q.pop();

        if(ux==it && uy==jt)
            return l[ux][uy];

        for(int i=0;i<4;i++){
            int vx=ux+ x[i];
            int vy= uy +y[i];

            if( isValid(vx,vy)){

                if(!v[vx][vy]){
                    q.push(make_pair(vx,vy));
                    l[vx][vy]=l[ux][uy]+1;
                    v[vx][vy]=1;
                }
            }
        }
    }

    return -1;
}

int main(){

    int t,caseno=1;


    scanf("%d",&t);

    while(t--){

        scanf("%d %d",&n,&m);

        pair<int,int> blossom,bubbles,buttercup,home;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                scanf(" %c",&g[i][j]);

                if(g[i][j]=='a'){
                    blossom= make_pair(i,j);
                    g[i][j]='.';
                }

                if(g[i][j]=='b'){
                    bubbles=make_pair(i,j);
                    g[i][j]='.';
                }


                if(g[i][j]=='c'){
                    buttercup=make_pair(i,j);
                    g[i][j]='.';
                }

                if(g[i][j]=='h'){
                    home= make_pair(i,j);
                    g[i][j]='.';
                }

            }
        }

        int disBlossom= bfs(blossom.first,blossom.second,home.first,home.second);

        memset(v,0,sizeof v);
        memset(l,0,sizeof l);

        int disBubble = bfs(bubbles.first,bubbles.second,home.first,home.second);

        memset(v,0,sizeof v);
        memset(l,0,sizeof l);

        int disButtercup= bfs(buttercup.first,buttercup.second,home.first,home.second);

        memset(v,0,sizeof v);
        memset(l,0,sizeof l);

        printf("Case %d: %d\n",caseno++,max(disBlossom,max(disButtercup,disBubble)));

    }

    return 0;
}
