#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll memo[19][11][2];

ll dp(string &n,int idx, int prev,int top){

    if(idx==n.size()) return 1;

    if(memo[idx][prev+1][top]!=-1)
        return memo[idx][prev+1][top];

    int maxi = (top)? n[idx] - '0' : 9;

    ll ans=0;
    for(int i=0;i<=maxi;i++){
        if (prev != -1 && i == prev)
            continue;

        ans+= dp(n, idx+1, (prev == -1 && i == 0 ? -1 : i) , top&&(i==maxi) );
    }

    return memo[idx][prev+1][top]=ans;
}

ll solve(ll n) {
    if (n < 0) return 0;
    string s = to_string(n);
    memset(memo, -1, sizeof(memo));
    return dp(s , 0,-1, 1);
}

int main(){

    ll a, b;
    memset(memo,-1,sizeof memo);
    cin >> a >> b;
    cout << solve(b) - solve(a-1) << "\n";

    return 0;
}
