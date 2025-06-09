#include <bits/stdc++.h>

using namespace std;

bool vs[200000];
set<int> g[200000];


bool dfs(int u, int parent){
    vs[u] = true;

    for (int v : g[u]) {
        if (!vs[v]) {
            if (dfs(v, u))
                return true;
        }
        else if (v != parent) {
            return true;
        }
    }
    return false;
}


int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, x;

    cin >> t;
    while(t--){

        cin >> n;

        for(int i=0;i<n;i++) vs[i] = false, g[i].clear();

        for(int i=0;i<n;i++){
            cin >> x; x--;
            g[i].insert(x);
            g[x].insert(i);
        }

        int components = 0;
        int cycles = 0;
        for(int i=0;i<n;i++){
            if(!vs[i]){
                if(dfs(i, -1))
                    cycles++;
                components++;
            }
        }

        cout << ( cycles != components) +  cycles << " "<< components << "\n";
    }


    return 0;
}

