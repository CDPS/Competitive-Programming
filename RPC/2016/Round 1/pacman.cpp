#include <bits/stdc++.h>

using namespace std;

char  g[50][50];
bool  visit[50][50][50][50];

int adx[4]={1,-1,0,0};
int ady[4]={0,0,1,-1};

int n,m;

map<long long,string> mp;

priority_queue<long long, vector<long long>, greater<long long> >pq;

struct node {
    pair<int,int>p1,p2;
    long long level;
    string path;

};

bool isvalid(int x,int y){

    if( (x>=0 && x<n)  && (y>=0 && y<m)){
        return true;
    }
    return false;
}

long long bfs(node s){

    queue<node> q;
    q.push(s) ;

    visit[s.p1.first][s.p1.second][s.p2.first][s.p2.second]=1;

    while(!q.empty()){

        node u = q.front();
        q.pop();

        if(u.p1.first==u.p2.first && u.p1.second==u.p2.second){
            pq.push(u.level);
            mp[u.level]= u.path;
        }

        for(int i=0;i<4;i++){
            node v;

            int vax = u.p1.first + adx[i];
            int vay=  u.p1.second+ ady[i];

            int vbx = u.p2.first + adx[i];
            int vby=  u.p2.second+ ady[i];


            if(!isvalid(vax,vay))
            {
                if(vax<0){
                    vax=n-1;
                }
                if(vax>=n){
                    vax=0;
                }
                if(vay<0){
                    vay=m-1;
                }
                if(vay>=m){
                    vay=0;
                }
            }

            if(g[vax][vay]=='G'){

                continue;
            }

            if(g[vax][vay]=='X' ){
                  vax = u.p1.first;
                  vay= u.p1.second;
            }

            if(!isvalid(vbx,vby)){
                if(vbx<0){
                    vbx=n-1;
                }
                if(vbx>=n){
                    vbx=0;
                }
                if(vby<0){
                    vby=m-1;
                }
                if(vby>=m){
                    vby=0;
                }
            }

             if(g[vbx][vby]=='G'){

                continue;
            }


            if(g[vbx][vby]=='X'){
                  vbx = u.p2.first;
                  vby= u.p2.second;
            }

            if(!visit[vax][vay][vbx][vby]){
                    v.p1 = make_pair(vax,vay);
                    v.p2= make_pair(vbx,vby);
                    v.level= u.level +1;

                    if(i==0){
                        v.path= u.path +"S";

                    }
                    if(i==1){
                        v.path= u.path +"N";
                    }
                     if(i==2){
                        v.path= u.path +"E";
                    }
                     if(i==3){
                        v.path= u.path +"W";
                    }

                    q.push(v);
                    visit[vax][vay][vbx][vby]=1;

            }
        }

    }
    return -1;
}

int main(){

    int t;
    scanf("%d",&t);

    while(t--){

        scanf("%d %d",&n,&m);
        vector< pair<int,int> > vec;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf(" %c",&g[i][j]);
                if(g[i][j]=='P'){
                     vec.push_back(make_pair(i,j));
                     g[i][j]='.';
                }

            }
        }

        node s;
        pq = priority_queue < long long, vector<long long>, greater<long long> >();
        mp.clear();
        s.p1 = vec[0];
        s.p2 = vec[1];
        s.level=0;
        s.path="";

        memset(visit,0,sizeof(visit));

        bfs(s);

        if(pq.empty()){
            printf("IMPOSSIBLE\n");
        }
        else{
            cout << pq.top()<< " "<< mp[pq.top()]<<"\n";
        }

    }


    return 0;
}
