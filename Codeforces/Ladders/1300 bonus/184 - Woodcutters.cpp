4#include <bits/stdc++.h>

using namespace std;

int dp[100000][3];
int  x[100000];
int  h[100000];

int main(){

    int n;
    cin >> n;

    for(int i=0;i<n;i++)
        cin >> x[i] >> h[i];

    dp[0][0] = 0;
    dp[0][1] = 1;
    dp[0][2] = 0;

    for(int i=1;i<n-1;i++){

        dp[i][0] = max({dp[i-1][0], dp[i-1][1] , dp[i-1][2]});

        if(x[i] - h[i] > x[i - 1])
            dp[i][1] = 1 + max( dp[i-1][0], dp[i-1][1] );

        if (x[i - 1] + h[i - 1] < x[i] - h[i])
            dp[i][1] =  max( 1 + dp[i-1][2], dp[i][1] );

        if (x[i] + h[i] < x[i + 1])
            dp[i][2] = 1 + max({dp[i-1][0], dp[i-1][1] , dp[i-1][2]});
    }

    cout << 1 + max({dp[n-2][0], dp[n-2][1] , dp[n-2][2]}) << "\n";
    return 0;
}
