
#include <bits/stdc++.h>

using namespace std;


int test,n, p, s,idx;

vector <int> t[50];
vector <int> g[50];
vector < vector<int> > tps;
stack <int> sa;

int visit[50];
int ciclo[50];
int ciclo2[50];

void dfs(int u){
    visit[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v= g[u][i];
        if(!visit[v])
            dfs(v);
    }
    sa.push(u);
}

void dfst(int u){
    tps[idx].push_back(u);
    visit[u]=1;

    for(int i=0;i<t[u].size();i++){
        int v= t[u][i];
        if(!visit[v])
            dfst(v);
    }
}

void dfs2(int u){

    visit[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v= g[u][i];
        if(ciclo[u] || ciclo2[u]){
            ciclo2[v]=1;
        }
        if(!visit[v])
            dfs2(v);
    }
}

void kosaraju(){

    for(int i=0;i<n;i++){
          visit[i]=0;
          ciclo[i]=0;
          ciclo2[i]=0;
    }
    for(int i=0;i<n;i++)
        if(!visit[i])
            dfs(i);

    for(int i=0;i<n;i++)
        visit[i]=0;

    tps = vector< vector<int> >(n);
    idx=0;
    while(!sa.empty()){

        int u= sa.top();
        sa.pop();

        if(!visit[u]){
            dfst(u);
            if(tps[idx].size()>1){
                for(int i=0;i<tps[idx].size();i++){
                    ciclo[ tps[idx][i] ] =1;
                }
            }
            idx++;
        }
    }
}

int main() {

    scanf("%d",&test);
    int caseno=1;

    while(test--){

        scanf("%d %d",&n,&s);
        vector<string> ps(n);
        string st;

        for(int i=0;i<n;i++){
            cin >> st;
            ps[i]=st;
        }

        for(int i=0;i<n;i++){
            int m;
            scanf("%d",&m);
            int v;
            for(int j=0;j<m;j++){
                scanf("%d",&v);
                g[i].push_back(v-1);
                t[v-1].push_back(i);
            }
        }

        kosaraju();

        for(int i=0;i<n;i++)
            visit[i]=0;

        dfs2(s-1);

        printf("Chain Email #%d:\n",caseno++);

        vector<string> res;


        for(int i=0;i<n;i++){
            if(ciclo2[i])
                res.push_back(ps[i]);
        }

        if(res.size()>0){
            for(int i=0;i< res.size()-1 ;i++){
                cout << res[i] << " ";
            }
            cout << res[res.size()-1] << "\n";
        }else{
            printf("Safe chain email!\n");
        }

        printf("\n");

        for(int i=0;i<n;i++){
            g[i].clear();
            t[i].clear();
        }
    }
    return 0;
}

