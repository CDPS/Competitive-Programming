#include <bits/stdc++.h>

using namespace std;

vector<int> g[4000];
string s;
int ans;

template <typename T1, typename T2>
pair<T1, T2> operator+(pair<T1, T2>& a, const pair<T1, T2>& b) {
    return {a.first + b.first, a.second + b.second};
}

pair<int,int> dfs(int x){

    if(g[x].size()==0) return { s[x]=='B', s[x]=='W'};

    pair<int, int> acc= { s[x]=='B', s[x]=='W'} ;

    for(int i=0;i<g[x].size();i++)
        acc = acc +  dfs(g[x][i]);

    if(acc.first == acc.second) ans++;

    return acc;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,x;

    cin >> t;

    while(t--){

        cin >> n;
        for(int i=2;i<=n;i++)
            cin >> x, g[x-1].push_back(i-1);
        cin >> s;

        ans =0;
        dfs(0);
        cout << ans << "\n";
        for(int i=0;i<n;i++) g[i].clear();
    }
    return 0;
}
