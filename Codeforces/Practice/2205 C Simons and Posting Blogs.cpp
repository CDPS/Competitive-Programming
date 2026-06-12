#include <bits/stdc++.h>

using namespace std;

int t, n, m;

vector<bool> vs;
vector< vector<int> > v;

bool isMin(int x, int y) {

    int i = 0, j = 0;
    while (true) {
        while (i <  v[x].size() && vs[v[x][i]]) i++;
        while (j <  v[y].size() && vs[v[y][j]]) j++;

        if (i ==  v[x].size() && j ==  v[y].size() ) return false;

        if (i ==  v[x].size()) return true;

        if (j ==  v[y].size() ) return false;

        if (v[x][i] != v[y][j])
            return v[x][i] < v[y][j];

        i++; j++;
    }
}

void solve(){

    cin >> n;

    v = vector< vector<int> > (n + 1);
    vs = vector<bool>(1000005, false);

    for(int i=1;i <= n; i++){
        cin >> m;

        vector<int> curr(m);
        for(int j=m-1; j >=0; j--)
            cin >> curr[j];

        vector<int> seen(1000005, false);
        for(int j= 0; j < m; j++)
            if(!seen[curr[j]])
                v[i].push_back(curr[j]), seen[curr[j]] = true;
    }

    v[0] =  vector<int>(1, 1000004) ;

    vector<bool> processed(n, false);
    for(int i = 0; i < n ; i++){

        int mini = 0;
        for(int j = 1 ; j <= n; j++)
            if(!processed[j] && isMin( j, mini ))
                mini = j;

        processed[mini] = true;
        for(int x : v[mini])
            if(!vs[x]){
                cout << x << " ";
                vs[x] = true;
            }
    }

    cout << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
