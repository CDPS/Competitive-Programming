#include <bits/stdc++.h>

using namespace std;


bool m[1000];
bool v[1001];

int l[1001];

vector <int> primes;

void criba(int tam){
    m[0] = false;
    m[1] = false;
    for(int i = 2; i <= tam; ++i)
        m[i] = true;

    for(int i = 2; i*i <= tam; ++i) {
        if(m[i]) {
            for(int h = 2; i*h <= tam; ++h)
                m[i*h] = false;
        }
    }
}

int bfs(int s,int t){

    queue<int> q;
    q.push(s);
    l[s]=0;

    while(!q.empty()){

        int u= q.front();
        q.pop();


        if(v[u]){
            continue;
        }
        v[u]=1;
        int i=0;
        while(primes[i]<u && i<primes.size()){

            if(u%primes[i]==0 && ( u + primes[i]<=t) ) {

                if(  l[u]+1< l[u+primes[i]]|| l[u+primes[i]]==0 ){
                        q.push(u+primes[i]);
                        l[u+primes[i]] = l[u] +1;
                }
            }
            i++;
        }
    }

    return l[t];
}

int main(){

    criba(1000);
    for(int i=2;i<1000;i++){
        if(m[i])
            primes.push_back(i);
    }

    int T,caseno=1;
    int s,t;
    scanf("%d",&T);

    while(T--){
         scanf("%d %d",&s,&t);

         for(int i=0;i<1001;i++){
            l[i]=0;
            v[i]=0;
         }


        if(s==t){
            printf("Case %d: 0\n",caseno++);
            continue;
        }

         int res = bfs(s,t);

        if(res!=0)
            printf("Case %d: %d\n",caseno++,res);
         else
            printf("Case %d: -1\n",caseno++);
    }
    return 0;
}
