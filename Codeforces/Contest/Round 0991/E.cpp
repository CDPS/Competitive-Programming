#include <bits/stdc++.h>

using namespace std;

string a, b,c;

int oo = 1000000;

int memo[1001][1001];

int dp(int i, int j){

    if(i == a.size() && j == b.size()) return 0;
    if(i > a.size()) return oo;
    if(j > b.size()) return oo;
    if(memo[i][j] != -1) return memo[i][j];

    int res = oo;
    if(i < a.size() && a[i] == c[i+j]) res = min(res, dp(i+1, j));
    if(j < b.size() && b[j] == c[i+j]) res = min(res, dp(i, j+1));
    return memo[i][j] = min(res, min(1 + dp(i, j+1), 1 + dp(i+1, j) ) );
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){

        cin >> a >> b >> c;

        memset(memo,-1, sizeof memo);
        cout << dp(0,0) << "\n";
    }
    return 0;
}
