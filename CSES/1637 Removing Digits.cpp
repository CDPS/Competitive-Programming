#include <bits/stdc++.h>

using namespace std;

int oo = 1e9;
int dp[1000001];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=0;i<= n;i++) dp[i] = oo;

    dp[0] = 0;
    for(int i=1;i<=n;i++){
        int temp = i;
        while(temp > 0 ){
            int d = temp%10; temp/= 10;
            if(d!= 0 && i-d >= 0)
                dp[i] =  min( dp[i], 1 + dp[i-d]);
        }
    }


    cout << dp[n] << "\n";

    return 0;
}

