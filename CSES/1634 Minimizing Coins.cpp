#include <bits/stdc++.h>

using namespace std;

int oo = 1e9;
int c[100], memo[1000001];

int main(){

    int n, k;
    cin >> n >> k;

    for(int i=0;i<=k;i++) memo[i]= oo;
    for(int i=0;i<n ;i++) cin >> c[i];

    memo[0] = 0;
    for(int i=1;i<=k;i++)
        for(int j=0;j<n;j++)
            if(i-c[j] >=0 )
                memo[i] = min(memo[i], 1 + memo[i-c[j]]);

    cout << ( memo[k] == oo? -1 : memo[k] ) << "\n";
    return 0;
}
