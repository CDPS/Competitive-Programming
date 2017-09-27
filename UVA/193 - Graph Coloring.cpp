#include <bits/stdc++.h>

using namespace std;

vector<int> g[100];
int         c[100];

int n,m,u,v,res,t;

bool isValid(int x){
    for(int i=0;i<g[x].size();i++)
        if( c[ g[x][i] ])
            return false;
    return true;
}

vector<int> r;

void fillr(){
    r.clear();
    for(int i=0;i<n;i++) if(c[i]) r.push_back(i);
}

void backtrack(int u){

    for(int i=0;i<n;i++){
        if(isValid(i) && !c[i])
          c[i]=1, backtrack(u+1), c[i]=0;
    }
    if(u>res) res=u ,fillr();
}

int main(){

    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&m);

        for(int i=0;i<n;i++){
            c[i]=0;g[i].clear();
        }

        for(int i=0;i<m;i++){
            scanf("%d %d",&u,&v); u--; v--;
            g[u].push_back(v); g[v].push_back(u);
        }
        res=-1;
        backtrack(0);

        printf("%d\n",res);
        for(int i=0;i<r.size();i++)
            printf("%d%c",r[i]+1,i==r.size()-1? '\n': ' ');
    }
    return 0;
}
