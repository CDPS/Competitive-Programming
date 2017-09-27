#include <bits/stdc++.h>


using namespace std;

vector<int> g[20001];
vector<int> nums;
bool v[20001];
bool s[20001];


int bfs(int e){

    queue<int> q;
    q.push(e);
    s[e]=0;
    int l=1,vm=0;
    v[e]=1;

    while(!q.empty()){

        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++){

            int ad=g[u][i];

            if(s[u]){
                //vampiro
                if(!v[ad]){
                    q.push(ad);
                    l++;
                    s[ad]=0;
                    v[ad]=1;
                }

            }else{
                //lykan
                if(!v[ad]){
                    q.push(ad);
                    s[ad]=1;
                    v[ad]=1;
                    vm++;
                }
            }
        }
    }

    return max(l,vm);
}

int main(){


    int t,caseno=1;
    scanf("%d",&t);

    while(t--){


        int n;
        scanf("%d",&n);

        int u,vs;

        for(int i=0;i<20001;i++){
            g[i].clear();
            v[i]=0;
            s[i]=0;
        }

        nums.clear();

        while(n--){
            scanf("%d %d",&u,&vs);
            g[u].push_back(vs);
            g[vs].push_back(u);

            nums.push_back(u);
            nums.push_back(vs);
        }

        sort( nums.begin(), nums.end() );
        nums.erase( unique( nums.begin(), nums.end() ), nums.end() );

        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            if( !v[ nums[i]] ){
                res+= bfs(nums[i]);
            }
        }

        printf("Case %d: %d\n",caseno++,res);
    }


    return 0;
}
