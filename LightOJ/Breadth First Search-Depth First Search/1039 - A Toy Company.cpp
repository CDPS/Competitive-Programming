#include <bits/stdc++.h>


using namespace std;

map<string,bool> forbidden;
map<string,bool> v;
map<string,int> l;

char ads[28]={'z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a'};

int x[6]={1,0,0,-1,0,0};
int y[6]={0,1,0,0,-1,0};
int z[6]={0,0,1,0,0,-1};

int bfs(string s,string t){

    queue<string> q;
    q.push(s);
    l[s]=0;

    while(!q.empty()){
        string u = q.front();
        q.pop();

        if(v[u]){
            continue;
        }

        if(u==t){
            return l[t];
            break ;
        }


        v[u]=1;

        for(int i=0;i<6;i++){
            int adx= u[0]+x[i] - 96;
            int ady= u[1]+y[i] -96;
            int adz= u[2]+z[i] -96;

            string ad;
            ad.push_back(ads[adx]);
            ad.push_back(ads[ady]);
            ad.push_back(ads[adz]);

            if( forbidden[ad] )
                continue;

            q.push(ad);
            l[ad] = l[u] +1;
        }
    }

    return -1;
}


int main(){

    int T,caseno=1;
    scanf("%d",&T);

    while(T--){
        string s,t;

        cin >> s >> t;

        int n;
        scanf("%d",&n);

        l.clear();
        v.clear();
        forbidden.clear();

        while(n--){
             string a,b,c;
             cin >> a >> b >> c;

             for(int i=0;i<a.size();i++){
                for(int j=0;j<b.size();j++){
                    for(int k=0;k<c.size();k++){
                        string f;
                        f.push_back(a[i]);
                        f.push_back(b[j]);
                        f.push_back(c[k]);
                        forbidden[f]=1;
                    }
                }
             }
        }


        if(forbidden[s] || forbidden[t]){
            printf("Case %d: -1\n",caseno++);
            continue;
        }

        if(s==t){
             printf("Case %d: 0\n",caseno++);
             continue;
        }

        int res =  bfs(s,t);
        printf("Case %d: %d\n",caseno++,res);

    }

    return 0;
}
