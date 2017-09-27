#include <bits/stdc++.h>

using namespace std;

char g[11][11];
long xs[4]={1,-1,0,0};
long ys[4]={0,0,1,-1};

map < pair<int,int>, bool> v;
map < pair<int,int>, int> l;


int bfs(int x,int y,char current,char target,int n){

    queue< pair<int,int> >q;
    char s=current;
    v.clear();
    l.clear();

    q.push(make_pair(x,y));
    l[make_pair(x,y)]=0;

    while(!q.empty()){

        int ux=q.front().first;
        int uy=q.front().second;

        q.pop();

        if(v[ make_pair(ux,uy) ] ){
            continue;
        }
        v[ make_pair(ux,uy) ]=1;

        if(g[ux][uy]==target){
            return l[make_pair(ux,uy)];
        }

        if(g[ux][uy] == s+1){

           int x=l[make_pair(ux,uy)];
           int  w = bfs(ux,uy,s+1,target,n);
           if(w==-1){
             return -1;
           }else{
                return  x+ w;
           }

        }

        for(int i=0;i<4;i++){

            int adx=ux+ xs[i];
            int ady=uy+ ys[i];

             if (adx >= 0 && adx < n && ady >= 0 && ady < n){
                    if( g[adx][ady] == '.' || (g[adx][ady] >= 'A' && g[adx][ady] <= s+1)){
                            q.push(make_pair(adx,ady));
                            l[make_pair(adx,ady)]= l[make_pair(ux,uy)]+1;
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
        int n;
        scanf("%d",&n);

        int x=0,y=0;
        char target='A';

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> g[i][j];

                if(g[i][j]=='A'){
                    x=i;
                    y=j;
                }
                if(g[i][j]>=66 && g[i][j]<=90) {
                        target++;
                }
            }
        }

        int res = bfs(x,y,'A',target,n);

        if(res>=0){
            printf("Case %d: %d\n",caseno++,res);
        }
        else{
            printf("Case %d: Impossible\n",caseno++);
        }

        l.clear();
        v.clear();
    }
    return 0;
}
