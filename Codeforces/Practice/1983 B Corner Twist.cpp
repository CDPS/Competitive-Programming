#include <bits/stdc++.h>

using namespace std;

int t, n, m;

bool solve(){

    cin >> n >> m;

    vector<string> g1(n), g2(n);

    for(int i=0;i<n;i++) cin >> g1[i];
    for(int i=0;i<n;i++) cin >> g2[i];


    vector<int> r1(m), r2(m),c1(n),c2(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int u = g1[i][j] - '0';
            int v = g2[i][j] - '0';
            r1[j]+= u; r1[j]%=3;
            r2[j]+= v; r2[j]%=3;
            c1[i]+= u; c1[i]%=3;
            c2[i]+= v; c2[i]%=3;
        }
    }

    bool check = true;
    for(int i=0;i<n;i++)
        check &= (c1[i] == c2[i]);

    for(int i=0;i<m;i++)
        check &= (r1[i] == r2[i]);

    return check;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    while(t--)
        cout << ( solve()? "YES" : "NO" )<< "\n";
    return 0;
}
