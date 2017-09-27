#include <bits/stdc++.h>


using namespace std;
vector < pair<int,int> > g1[100];
vector < pair<int,int> > g2[100];
bool v[100];

int main(){

    int t,caseno=1;
    scanf("%d",&t);


    while(t--){
        int n;
        scanf("%d",&n);
        int y=n;
        while(n--){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            g1[a-1].push_back(make_pair(b-1,c));
            g2[b-1].push_back(make_pair(a-1,c));
        }

        memset(v,0,100);
        int res1=0,s,res2=0,t;
        int m=g1[0].size();


        if(m==0){
            res1=g2[0][0].second;
            s=g2[0][0].first;

            res2=g2[0][1].second;
            t=g2[0][1].first;
        }
        if(m==1){
            s=g1[0][0].first;

            res2=g2[0][0].second;
            res2+=g1[0][0].second;
            t=g2[0][0].first;
        }

        if(m==2){
            s=g1[0][0].first;
            res1=g1[0][1].second;
            t=g1[0][1].first;
            res2=g1[0][0].second;
        }


        queue<int> q;
        q.push(s);
        v[0]=1;
        while(!q.empty()){

            int u= q.front();
            q.pop();

            if(v[u])continue;

            v[u]=1;
            int ta=g1[u].size();
            if(ta==0){

                if( v[g2[u][0].first]){

                    if(!v[g2[u][1].first]){
                        q.push(g2[u][1].first);
                        res1+=g2[u][1].second;
                    }
                }else{
                     q.push(g2[u][0].first);
                     res1+=g2[u][0].second;
                }
            }else if(ta==1){
                    if(!v[g1[u][0].first]){
                        q.push(g1[u][0].first);
                    }else{
                         if(!v[g2[u][0].first]){
                            q.push(g2[u][0].first);
                            res1+=g2[u][0].second;
                        }
                    }
            }
            else{
                for(int i=0;i<g1[u].size();i++){
                    if(!v[g1[u][i].first]){
                        q.push(g1[u][i].first);
                        break;
                    }
                }

            }
        }



         for(int i=0;i<y;i++){
            v[i]=0;
        }



        q.push(t);
        v[0]=1;
        while(!q.empty()){

            int u= q.front();
            q.pop();

            if(v[u])continue;

            v[u]=1;
            int ta=g1[u].size();
            if(ta==0){

                if( v[g2[u][0].first]){

                    if(!v[g2[u][1].first]){
                        q.push(g2[u][1].first);
                        res2+=g2[u][1].second;
                    }
                }else{
                     q.push(g2[u][0].first);
                     res2+=g2[u][0].second;
                }
            }else if(ta==1){
                    if(!v[g1[u][0].first]){
                        q.push(g1[u][0].first);
                    }else{
                         if(!v[g2[u][0].first]){
                            q.push(g2[u][0].first);
                            res2+=g2[u][0].second;
                        }
                    }
            }
            else{
                for(int i=0;i<g1[u].size();i++){
                    if(!v[g1[u][i].first]){
                        q.push(g1[u][i].first);
                        break;
                    }
                }

            }
        }

        printf("Case %d: %d\n",caseno++,min(res1,res2));
        for(int i=0;i<y;i++){
            g1[i].clear();
            g2[i].clear();
        }
    }

    return 0;
}
