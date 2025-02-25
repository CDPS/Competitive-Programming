#include <bits/stdc++.h>

using namespace std;

int const m = 1e9 + 7;
int c[100], dp[1000001];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    for(int i=0;i<n;i++) cin >> c[i];

    dp[0] = 1;
    for(int j=0;j<n;j++)
        for(int i=1;i<=k;i++)
            if(i-c[j]>=0)
                dp[i] = (dp[i] + dp[i-c[j]])%m;

    cout << dp[k] << "\n";
    return 0;
}
