#include <bits/stdc++.h>

using namespace std;

int  a[200000];
int dp[200001];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;

    cin >> t;
    while(t--){

        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i], dp[i] = 0;
        dp[n] = 0;

        for(int i=n-1;i>=0;i--){
            dp[i] = dp[i+1];
            if(i + a[i] <= n-1 )
                dp[i] = max(dp[i],  1 + a[i] + dp[ i+a[i]+1] );
        }

        cout << n - dp[0] << "\n";
    }
    return 0;
}
