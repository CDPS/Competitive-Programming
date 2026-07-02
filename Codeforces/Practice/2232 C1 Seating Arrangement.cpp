#include <bits/stdc++.h>

using namespace std;

int t, n, x, s;
string stream;

int solve(){


    cin >> n >> x >> s >> stream;


    vector< vector<int> > dp(n  + 1, vector<int>(x + 1 , -1) );

    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        char person = stream[i-1]; 
        
        for(int j = 0; j <= x; j++){
            
            if (dp[i-1][j] != -1)
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            
            
            if ((person == 'I' || person == 'A') && j > 0) 
                if (dp[i-1][j-1] != -1) 
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                
            if ((person == 'E' || person == 'A')) {
                if (dp[i-1][j] != -1) {
                    int total = j * s, taken = dp[i-1][j];
                    if (total - taken > 0) 
                        dp[i][j] = max(dp[i][j], dp[i-1][j] + 1);
                }
            }
        }
    }

    int ans = 0;
    for(int i= 1; i<= x; i++)
         ans = max(ans, dp[n][i]);
        
    return ans;
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
        cout << solve() << "\n";
    
    return 0;
}