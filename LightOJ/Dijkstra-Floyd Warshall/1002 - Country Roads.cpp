#include <bits/stdc++.h>


using namespace std;

const int INF = 2000000000;

vector< pair<int,int> >g[501];

int dis[501];
bool visit[501];

bool visitM[501][501];


int main(){

    int t,caseno=1;
    scanf("%d",&t);


    while(t--){

        int n,m;
        scanf("%d %d",&n,&m);

        int u,v,w;

        for(int i=0;i<m;i++){
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back(make_pair(w,v));
            g[v].push_back(make_pair(w,u));
        }

        int s;
        scanf("%d",&s);

        priority_queue<pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > > pq;

        for(int i=0;i<n;i++){
            visit[i]=0;
            dis[i]=INF;
        }

        pq.push(make_pair (0,s));
        dis[s]= 0;

        while (!pq.empty()){

            pair<int,int> u = pq.top();
            pq.pop();

            int ux= u.second;

            for(int i=0;i< g[ux].size();i++){

                int v= g[ux][i].second;

                int wv=g[ux][i].first;

                if(visit[v]){

                    if(dis[v]> max(dis[ux],wv)){
                        dis[v]=max(dis[ux],wv);

                        pq.push(make_pair(dis[v],v) );
                    }

                }else{

                    if( wv > dis[ux]){
                        dis[v]= wv ;
                        pq.push (make_pair (dis[v],v));
                        visit[v]=1;
                    }else{
                        dis[v]=dis[ux];
                        pq.push (make_pair (dis[v],v));
                        visit[v]=1;
                    }

                }

            }
        }


        printf("Case %d:\n",caseno++);

        for(int i=0;i<n;i++){
            g[i].clear();
            if(i==s){
                printf("0\n");
                continue;
            }

            if(dis[i]!=INF)
                printf("%d\n",dis[i]);
            else
                 printf("Impossible\n");
        }


    }


    return 0;
}
