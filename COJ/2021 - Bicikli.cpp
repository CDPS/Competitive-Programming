#include <bits/stdc++.h>

using namespace std;

int n,m;

vector<int> g[10000];
vector<int> t[10000];

vector< vector<int> > tps;
stack<int> s;

int visit[10000],c[10000];
int idx;

void dfs(int u){
    visit[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v= g[u][i];
        if(!visit[v])
            dfs(v);
    }
    s.push(u);
}

void dfs2(int u,int s){
    visit[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v= g[u][i];
        if(v==1 && s==1)
            c[1]=1;
        if(!visit[v]){
            dfs2(v, 0|c[v]);
        }
    }
}

void dfst(int u){
    visit[u]=1;
    tps[idx].push_back(u);
    for(int i=0;i<t[u].size();i++){
        int v= t[u][i];
        if(!visit[v])
            dfst(v);
    }
}

long long dp[10000];
int aux=0;
long long suma(long long a, long long b){

	if(a+b>=1000000000){
		aux=1;
	}
	return ((a%1000000000)+(b%1000000000))%1000000000;
}

long long dfsr(int u){
    if(u==1) return 1;
    if(dp[u]!=-1) return dp[u];

    long long ans=0;
    for(int i=0;i<g[u].size();i++){
    	int v= g[u][i];
    	if(c[v])continue;
        ans= suma( ans, dfsr(v));
    }
    return dp[u]=ans;
}

bool kosaraju(){

   for(int i=0;i<n;i++){
        visit[i]=0;
        c[i]=0;
   }
    for(int i=0;i<n;i++){
        if(!visit[i])
          dfs(i);

        if(i==0){
            if(!visit[1])
                return false;
        }
    }

   for(int i=0;i<n;i++)
        visit[i]=0;

    tps = vector< vector<int> >(n);
    idx=0;

    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(!visit[u]){
            dfst(u);
            if(tps[idx].size() > 1){
                 for(int j=0;j<tps[idx].size();j++){
                      c[tps[idx][j]]=1;
                }
            }
            idx++;
        }
    }

    return true;
}


int main(){

    scanf("%d %d",&n,&m);
    int u,v;

    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        u--; v--;
        g[u].push_back(v);
        t[v].push_back(u);
    }

    if(kosaraju()){

        for(int i=0;i<n;i++)
            visit[i]=0;

        dfs2(0,c[0]);
        if(c[1]==1)
            printf("inf\n");
        else{

        	aux=0;
        	for(int i=0;i<n;i++)
        	       dp[i]=-1;

        	long long res = dfsr(0);

            if(aux==0)
                printf("%lld\n",res) ;
            else
                printf("%09lld\n",res) ;
        }

    }else{
        printf("0\n");
    }

    return 0;
}
