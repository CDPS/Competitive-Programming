#include <bits/stdc++.h>

using namespace std;

int n,k,d, m = 1000000007;

int memo[101][2];

int dp(int acc, bool l){

    if(acc > n)  return 0;

    if(acc == n && l) return 1;

    if(memo[acc][l]!=-1) return memo[acc][l];

    int ans =0;
    for(int i=1;i<=k;i++)
        ans = ( (dp(acc+i, l || i>=d )%m)  + (ans%m) )%m;

    return memo[acc][l]= ans;
}

int main(){
    memset(memo,-1, sizeof memo);
    cin >> n >> k >> d;
    cout << dp(0,0) << "\n";
    return 0;
}
