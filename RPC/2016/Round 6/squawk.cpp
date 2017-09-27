#include <bits/stdc++.h>

using namespace std;

vector<int> g[100];

int n, m,s,t;

int bfs(int s,int t){

    int res=0;
    int ms[200];

    memset(ms, 0 , sizeof ms);

    ms[s]=1;

    vector<int> child ,inf;  inf.push_back(s);

    for(int i=0;i<t;i++){

        child = vector<int>();

        for(int j=0;j<inf.size();j++){

            int u = inf[j];

            for(int k=0;k< g[u].size();k++) {
                int v = g[u][k];
                ms[v]+= ms[u];
                child.push_back(v);
            }

            ms[u]=0;
        }

        sort( child.begin(), child.end() );
        child.erase( unique( child.begin(), child.end() ), child.end() );

        inf=child;
    }

    for(int i=0;i<n;i++)
        res+=ms[i];

    return res;
}

int main(){


    cin >> n>> m >> s >>t;

    int u,v;

    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    long long res;

    if(t==0)
        res=0;
    else
        res = bfs(s,t);

    printf("%lld\n",res);

    return 0;
}
