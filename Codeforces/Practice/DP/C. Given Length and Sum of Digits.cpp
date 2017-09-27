#include <bits/stdc++.h>

using namespace std;

int memo[100][100][901];

int n,m;

int inf = 1000000;


int main(){

    cin >> n >> m;
    memset(memo,-1,sizeof memo);

    int ans = dp(0,0,0);

    if(ans == inf)
        cout << "-1 -1";
    else{

        stringstream ss; ss << ans;

        string maxi ; ss >> maxi;

        sort(maxi.begin(),maxi.end()); reverse(maxi.begin(),maxi.end());

        cout << ans << " " << maxi;
    }
    return 0;
}
