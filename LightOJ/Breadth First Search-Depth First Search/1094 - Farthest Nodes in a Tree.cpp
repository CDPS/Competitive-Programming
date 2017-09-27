#include <bits/stdc++.h>

using namespace std;

vector < pair<int,int> > g[30000];
bool visit[30000];
long level[30000];

int main(){

    int caseno=1;
    int t;
    scanf("%d",&t);

    while(t--){
        int n;
        scanf("%d",&n);
        int y=n;

        memset(visit,0,n);
        memset(level,0,n);
        n--;
        int s;

        while(n--){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            s=u;
            g[u].push_back(make_pair(v,w));
            g[v].push_back(make_pair(u,w));
        }

        queue<int> q;
        priority_queue<long>pq;
        map< long, int> mp;
        q.push(s);

        while(!q.empty()) {
            int ux= q.front();
            q.pop();

            if(visit[ux] ){
                continue;
            }
            visit[ux]=1;
            int m=g[ux].size();

            for(int j=0;j<m;j++){
                int ad=g[ux][j].first;
                int we=g[ux][j].second;
                if(visit[ad])continue;
                q.push(ad);
                if( level[ux]+we > level[ad]){
                        level[ad]= level[ux]+we;
                        pq.push(level[ad]);
                        mp[level[ad]]=ad;
                }
            }
        }

        int t = mp[pq.top()];
        pq = priority_queue <long>();
        q = queue<int>();

        for(int i=0;i<y;i++){
            level[i]=0;
            visit[i]=0;
        }
        q.push(t);

        while(!q.empty()) {
            int ux= q.front();
            q.pop();

            if(visit[ux] ){
                continue;
            }
            visit[ux]=1;
            int m=g[ux].size();

            for(int j=0;j<m;j++){
                int ad=g[ux][j].first;
                int we=g[ux][j].second;
                if(visit[ad])continue;
                q.push(ad);
                if( level[ux]+we > level[ad]){
                        level[ad]= level[ux]+we;
                        pq.push(level[ad]);
                }
            }
        }

        for(int i=0;i<y;i++){
            g[i].clear();
        }
        printf("Case %d: %ld\n",caseno++, pq.top() );
    }
    return 0;
}
