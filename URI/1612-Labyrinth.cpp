#include <bits/stdc++.h>

using namespace std;

char g[501][501];

int adx[4]={1,-1,0,0};
int ady[4]={0,0,1,-1};
bool v[501][501];
int l[501][501];

int main(){


    int n,m;
    scanf("%d %d",&n,&m);
    while(true){

        if(n==0 && m==0){
            break;
        }

        int si,sj;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf(" %c",&g[i][j]);
                v[i][j]=0;
                l[i][j]=0;

                if(g[i][j]=='.'){
                    si=i;
                    sj=j;
                }
            }
        }

    queue< pair<int,int> > q;
    priority_queue<int>pq;
    map<int ,pair<int,int> > mp;
    q.push( make_pair(si,sj) ) ;

    v[si][sj]=1;
    l[si][sj]=0;

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
                    l[vx][vy]= 1+ l[ux][uy];
                    v[vx][vy]=1;
                    pq.push(l[vx][vy]);
                    mp[l[vx][vy]]=make_pair(vx,vy);
                }
            }
        }
    }

    si=mp[pq.top()].first;
    sj=mp[pq.top()].second;

    pq = priority_queue <int>();

    q.push( make_pair(si,sj) ) ;

    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[i][j]=0;
                l[i][j]=0;
            }
    }

    v[si][sj]=1;
    l[si][sj]=0;

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
                    l[vx][vy]= 1+ l[ux][uy];
                    v[vx][vy]=1;
                    pq.push(l[vx][vy]);
                }
            }
        }
    }

    printf("%d\n",pq.top());
    scanf("%d %d",&n,&m);

    }

    return 0;
}
