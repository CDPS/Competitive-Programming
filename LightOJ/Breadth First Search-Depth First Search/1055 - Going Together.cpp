
#include <bits/stdc++.h>

using namespace std;

char  g[10][10];
bool  visit[10][10][10][10][10][10];

int adx[4]={1,-1,0,0};
int ady[4]={0,0,1,-1};

int n;

struct node {
    pair<int,int>ai;
    pair<int,int>bi;
    pair<int,int>ci;
    long long level;
};


bool isvalid(int x,int y){

    if( (x>=0 && x<n)  && (y>=0 && y<n)){
         if(g[x][y]!='#'){
            return true;
         }
    }
    return false;
}

map< node , bool> mp;

long long bfs(node s){

    queue<node> q;
    q.push(s) ;

    visit[s.ai.first][s.ai.second][s.bi.first][s.bi.second][s.ci.first][s.ci.second]=1;

    while(!q.empty()){

        node u = q.front();
        q.pop();

        if(g[u.ai.first][u.ai.second]=='X' && g[u.bi.first][u.bi.second]=='X'  && g[u.ci.first][u.ci.second]=='X'){
            return u.level;
        }

        for(int i=0;i<4;i++){
            node v;

            int vax = u.ai.first + adx[i];
            int vay= u.ai.second+ ady[i];

            int vbx = u.bi.first + adx[i];
            int vby= u.bi.second+ ady[i];

            int vcx= u.ci.first + adx[i];
            int vcy= u.ci.second+ ady[i];

            if( !isvalid(vax,vay)){
                vax = u.ai.first;
                vay= u.ai.second;
            }

            if(!isvalid(vbx,vby)){
                vbx = u.bi.first;
                vby= u.bi.second;
            }

            if(!isvalid(vcx,vcy)){
                vcx = u.ci.first;
                vcy= u.ci.second;
            }

            if( (vax==vbx && vay==vby) || (vax==vcx && vay==vcy)){
                    vax = u.ai.first;
                    vay= u.ai.second;

                    if( vax==vbx && vay==vby) {
                         vbx = u.bi.first;
                        vby=  u.bi.second;
                    }
                    if( vax==vcx && vay==vcy){
                        vcx = u.ci.first;
                        vcy= u.ci.second;
                    }
            }

            if( (vbx==vax && vby==vay) || (vbx==vcx && vby==vcy)){
                    vbx = u.bi.first;
                    vby=  u.bi.second;

                     if( vax==vbx && vay==vby) {
                         vax = u.ai.first;
                         vay=  u.ai.second;
                     }

                     if( vbx==vcx && vby==vcy){
                         vcx = u.ci.first;
                         vcy= u.ci.second;
                     }
            }

            if((vcx==vax && vcy==vay) || (vbx==vcx && vby==vcy)){
                vcx = u.ci.first;
                vcy= u.ci.second;

                if( vax==vcx && vay==vcy){
                        vax = u.ai.first;
                        vay= u.ai.second;
                }

                if( vbx==vcx && vby==vcy){
                         vbx = u.bi.first;
                         vby= u.bi.second;
                }
            }

            if(!visit[vax][vay][vbx][vby][vcx][vcy]){
                    v.ai = make_pair(vax,vay);
                    v.bi= make_pair(vbx,vby);
                    v.ci= make_pair(vcx,vcy);
                    v.level= u.level +1;
                    q.push(v);
                    visit[vax][vay][vbx][vby][vcx][vcy]=1;
            }
        }
    }


    return -1;
}
int main(){

    int t,caseno=1;
    scanf("%d",&t);

    while(t--){


        scanf("%d",&n);

        pair<int,int> a,b,c;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf(" %c",&g[i][j]);
                if(g[i][j]=='A'){
                     a = make_pair(i,j);
                     g[i][j]='.';
                }
                if(g[i][j]=='B'){
                    b= make_pair(i,j);
                    g[i][j]='.';
                }

                if(g[i][j]=='C'){
                    c=make_pair(i,j);
                    g[i][j]='.';
                }
            }
        }

        node s;
        s.ai=a;
        s.bi=b;
        s.ci=c;
        s.level=0;
        memset(visit,0,sizeof(visit));

        long long res= bfs(s);

        if(res==-1)
            printf("Case %d: trapped\n",caseno++);
        else
            printf("Case %d: %lld\n",caseno++,res);
    }
    return 0;
}
