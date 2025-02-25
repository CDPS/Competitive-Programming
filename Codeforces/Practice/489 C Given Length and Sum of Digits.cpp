#include <bits/stdc++.h>

using namespace std;

int memo[100][901];

int n,m;

int inf = 1000000;

int dp (int idx,int acc){

    if(idx==n && acc == m ) return num;
    if(acc > m) return 0;
    if(idx ==n ) return 0;
    if(memo[idx][acc] !=-1) return memo[idx][acc];

    int ans = 0;
    for(int i=0;i<=9;i++)
        ans += dp(idx+1, acc + i);

    return memo[idx][acc]= ans;
}

int main(){

    cin >> n >> m;
    memset(memo,-1,sizeof memo);

    int ans = dp(0,0,0);

    if(ans == 0)
        cout << "-1 -1";
    else{

        stringstream ss; ss << ans;

        string maxi ; ss >> maxi;

        sort(maxi.begin(),maxi.end()); reverse(maxi.begin(),maxi.end());

        cout << ans << " " << maxi;
    }
    return 0;
}
