#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

vector<bool> vs;
vector<pair<int,int>> v;

int n, op, a, b;


bool dfs(int x, int y){

    if(x == y)
        return true;

    vs[x] = true;

    bool found = false;
    for(int i=0;i<v.size();i++)
        if ( !vs[i] && ( (v[x].f  > v[i].f  && v[x].f  <  v[i].s )  || (v[x].s  > v[i].f  && v[x].s  < v[i].s )  ) )
            found |= dfs(i, y);

    return found;
}

void solve(){

    cin >> n;
    while(n--){
        cin >> op >> a >> b;
        if(op ==2 ){
            vs = vector<bool>(v.size(), false);
            cout << (dfs(a-1, b -1)? "YES" : "NO" )<< "\n";
        }
        else
            v.push_back({a, b});
    }
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

