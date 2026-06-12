#include <bits/stdc++.h>

using namespace std;

int t = 1, n;

string a[100];
int d[26];
vector<int> g[26];

void solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=0;i<n-1;i++){

        int m = min(a[i].size(), a[i+1].size());
        bool found = false;
        for(int j=0;j<m;j++){
            if( a[i][j] != a[i+1][j]){
                g[ a[i][j]-'a' ].push_back( a[i+1][j]-'a' );
                found = true;
                d[a[i+1][j]-'a']++;
                break;
            }
        }

        if(!found && a[i].size() > a[i+1].size()){
            cout << "Impossible" << "\n";
            return;
        }
    }

    queue<int> q;
    for (int i = 0; i < 26; i++)
        if (d[i] == 0)
            q.push(i);

    string result = "";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result += (char)(u + 'a');
        for (int v : g[u]) {
            d[v]--;
            if (d[v] == 0)
                q.push(v);
        }
    }

    if (result.length() == 26) {
        cout << result << endl;
    } else {
        cout << "Impossible" << endl;
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
