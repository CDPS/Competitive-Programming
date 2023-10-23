#include <bits/stdc++.h>

using namespace std;

int oo = 10000000;
vector<int> a[4001];
bool g[4001][4001];

int n,m;

int main(){

    cin >> n >> m;

    int u,v;
    for(int i =0;i<m;i++){
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        g[u][v] = 1;
        g[v][u] = 1;
    }

    int res = oo;
    for(int i = 1; i<= n;i++){
        for(int j = 0; j<a[i].size(); j++ ){
            for(int k = j+1; k<a[i].size(); k++ ){
                if( g[ a[i][j] ][ a[i][k] ] ){
                    int calc = a[i].size() + a[ a[i][j] ].size() + a[ a[i][k] ].size() - 6;
                    res = min(res, calc);
                }
            }
        }
    }

    cout << ( res==oo ? -1 : res ) << "\n";
    return 0;
}

