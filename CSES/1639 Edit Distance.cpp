#include <bits/stdc++.h>

using namespace std;

int memo[5001][5001];

string a, b;

int dp(int i, int j){

    if(i== a.size()) return memo[i][j] = b.size() - j;
    if(j== b.size()) return memo[i][j] = a.size() - i;
    if(memo[i][j] != -1) return memo[i][j];

    if(a[i] == b[j] )
        return memo[i][j] = dp(i+1,j+1);

    return memo[i][j] = 1 + min({ dp(i+1,j+1), dp(i,j+1) ,  dp(i+1,j)});
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> a >> b;

    memset(memo, -1, sizeof memo );

    cout << dp(0,0) << "\n";

    return 0;
}
