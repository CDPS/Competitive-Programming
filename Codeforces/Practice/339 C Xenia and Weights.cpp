#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;


bool vs[10001][11][11];
vector<int> ans;

bool dfs(int acc, int diff, int last){

    if(acc == n) return true;

    if(vs[acc][diff][last]) return false;

    vs[acc][diff][last] = true;
    for(int i=1;i<=10;i++)
        if(s[i-1] == '1' && i != last && i > diff )
            if(dfs(acc + 1, i- diff, i)){
                ans.push_back(i);
                return true;
            }

    return false;
}

void solve(){

    cin >> s >> n;

    if(!dfs(0,0,0)){
        cout << "NO" << "\n";
        return;
    }

    reverse(ans.begin(), ans.end());
    cout << "YES" << "\n";
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " \n"[i==ans.size()-1];
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    t = 1;
    while(t--)
        solve();

    return 0;
}

