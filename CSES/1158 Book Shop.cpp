#include <bits/stdc++.h>

using namespace std;

int oo = 2e9;
int w[1000],  p[1000];
int memo[100001][1000];

int n , x;

int dp(int W, int i){
    if(i==n && W >=0 ) return 0;
    if(W < 0) return -oo;
    if(memo[W][i]!=-1) return memo[W][i];
    return memo[W][i] = max( p[i] + dp( W-w[i], i + 1 ), dp(W, i + 1) );
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);


    cin >> n >> x;

    for(int i=0;i<n;i++) cin >> w[i];
    for(int i=0;i<n;i++) cin >> p[i];


    for(int i=0;i<n;i++){
        for(int j=1;j<=x;j++){

        }
    }
    cout << dp(x, 0) << "\n";

    return 0;
}
