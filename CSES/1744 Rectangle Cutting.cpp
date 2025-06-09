#include <bits/stdc++.h>

using namespace std;

int memo[501][5001];
const int oo = 1e9;

int dp(int a, int b){

    if(a==b) return 0;
    if(a==1) return b-1;
    if(b==1) return a-1;
    if(memo[a][b]!= -1) return memo[a][b];

    int ans = oo;
    for(int i=1;i*2<=a;i++)
        ans = min(ans,  dp(i, b) + dp(a-i, b) );

    for(int i=1;i*2<=b;i++)
        ans = min(ans,  dp(a, i) + dp(a, b-i) );

    return memo[a][b] = 1 + ans;
}

int main(){

    memset(memo, -1, sizeof memo);

    int a, b;
    cin >> a >> b;

    cout << dp(a, b) << "\n";

    return 0;
}
