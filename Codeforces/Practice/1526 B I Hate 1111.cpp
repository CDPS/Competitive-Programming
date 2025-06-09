#include <bits/stdc++.h>

using namespace std;

bool dp[1100];

bool check(int x){
    if(x > 1099 ) return true;
    return dp[x];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    dp[0] = true;
    for(int i=11;i<1100;i++){
        if(i>=11)  dp[i] |= dp[i-11];
        if(i>=111) dp[i] |= dp[i-111];
    }

    int t, n;

    cin >> t;

    while(t--){

        cin >> n;

        cout << (check(n)? "YES" : "NO" ) << "\n";
    }
    return 0;
}
