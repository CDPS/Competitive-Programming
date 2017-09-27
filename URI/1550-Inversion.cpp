#include <bits/stdc++.h>

using namespace std;

map<int, int> nivel;
map<int, bool> visitados;

int n, m;

int bfs (int n) {

    queue<int> cola;
    cola.push(n);

    while(!cola.empty()) {

        int u = cola.front();
        cola.pop();

        if (visitados[u]) {

            continue;

        }

        visitados[u]=true;

        if(u==m){

            return nivel[u];
        }

        int u1=u+1;

        int u2=u;
        int r;
        int i=0;

        while (u2 != 0)
        {
            r=u2%10;
            u2=u2/10;
            i=i*10+r;
        }

        u2=i;

        if(nivel[u1]==0 && u1>0) {

            cola.push(u1);
            nivel[u1]= nivel[u]+1;
        }

        if(nivel[u2]==0 & u1<=10000) {

            cola.push(u2);
            nivel[u2]= nivel[u]+1;
        }


    }
}


int main() {

    int t;
    scanf("%d",&t);
    while (t--){

        scanf("%d %d", &n, &m);
        printf("%d\n", bfs(n));

        nivel.clear();
        visitados.clear();
    }

    return 0;
}
