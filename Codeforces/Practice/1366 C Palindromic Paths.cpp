#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int t, n, m;

int a[30][30];

int solve(){

    cin >> n >> m;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];


    int sz = n + m - 1;

    vector<pair<int,int> > v(sz, {0,0});
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]) v[i + j].f++;
            else v[i + j].s++;
        }
    }

    int ans = 0;
    for(int i=0; i< sz/2; i++){
        int ones = v[i].f + v[sz-1-i].f ;
        int twos = v[i].s + v[sz-1-i].s ;
        int total = ones + twos;
        ans += min(  total - ones, total - twos);
    }

    return  ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
