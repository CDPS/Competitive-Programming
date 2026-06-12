#include <bits/stdc++.h>

using namespace std;

int t = 1, n, s, p, q;
char d;
int g[2][100001];

void solve(){

    cin >> n >> s;

    while(n--){
        cin >> d >> p >> q;
        g[d=='B'][p]+=q;
    }

    vector<int> curr;
    for(int i=0, j = 0; j< s  && i<=100000; i++)
        if(g[0][i] != 0)
            curr.push_back(i), j++;

    for(int i=curr.size()-1; i>=0; i--)
        cout << 'S' << " " << curr[i] << " " << g[0][curr[i]] << "\n";

    for(int i=100000, j = 0; j< s  && i>=0; i--){
        if(g[1][i] != 0){
            cout << 'B' << " " << i << " " << g[1][i] << "\n";
            j++;
        }
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
