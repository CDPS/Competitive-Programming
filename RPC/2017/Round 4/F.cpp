#include <bits/stdc++.h>

using namespace std;

string s;
int k;

int dp[1000];

int f( int idx, char ant ){

    if(idx ==s.size())
        return 0;

    if(dp[idx]!=-1)
        return dp[idx];

    if( s[idx]  < ant )
        return f(idx+1, ant);

    int res1 =  1 + f(idx+1, char( ( s[idx] - 'a' + k ) %26 + 'a'));
    int res2 =  f(idx+1, ant);

    return dp[idx]= max(res1,res2);
}

int main(){

    int t;
    cin >> t;
    while(t--){
        cin >> s  >> k;

        memset(dp,-1,sizeof dp);
        int res= f(0,'@');
        cout << res << "\n";
    }
    return 0;
}
