#include <bits/stdc++.h>

using namespace std;

bool dp[100001];

int main(){

    int n, x;
    cin >> n;

    dp[0] = true;
    for(int i=0;i<n;i++){
        cin >> x;
        for(int j=100000;j>=x;j--)
            dp[j] |= dp[j-x];
    }

    int acc =0;
    for(int i=1;i<=100000;i++)
        if(dp[i]==1) acc++;

    cout << acc << "\n";
    for(int i=1;i<=100000;i++)
        if(dp[i]==1) cout << i << " ";

    return 0;
}
