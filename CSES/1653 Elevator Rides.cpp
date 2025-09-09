#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;
int w[20];
pair<int, int> dp[1<<20];

int main(){

    int n, W;

    cin >> n >> W;
    for(int i=0;i<n;i++) cin >> w[i];

    for(int i=0;i<(1<<n);i++) dp[i] = {n+1, oo};

    dp[0] = {1,0};
    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if((mask&(1<<i))==0){
                pair<int, int> curr;
                if(dp[mask].second + w[i] <= W)
                    curr = {dp[mask].first, dp[mask].second + w[i] };
                else
                    curr = {dp[mask].first + 1, w[i] };

                dp[mask ^ (1<<i) ] = min( dp[mask ^ (1<<i) ] , curr);
            }
        }
    }
    cout << dp[ (1<<n)-1 ].first << "\n";

    return 0;
}
