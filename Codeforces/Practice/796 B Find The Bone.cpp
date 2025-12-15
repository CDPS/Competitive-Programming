#include <bits/stdc++.h>

using namespace std;

int n, m, k, x, u, v;

bool   a[1000001];
bool pos[1000001];

int solve(){

    cin >> n >> m >> k;

    for(int i=0;i<m;i++)
        cin >> x, a[x] = true;

    pos[1] = true;
    bool check = false;
    while(k--){
        cin >> u >> v;
        check |= (pos[u] && a[u]) || (pos[v] && a[v]);
        if(!check )
            swap(pos[u], pos[v]);
    }

    for(int i=1;i<=n;i++)
        if(pos[i])
            return i;

    return 1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";
}
