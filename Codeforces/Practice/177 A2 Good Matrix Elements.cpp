#include <bits/stdc++.h>

using namespace std;

int t = 1, n;
int a[101][101];

int solve(){

    cin >> n;
    for(int i=0;i<n ;i++)
        for(int j=0;j<n ;j++)
            cin >> a[i][j];

    int sum = 0;
    for(int i=0; i< n; i++)
        sum+= a[i][i];
    for(int i=n-1; i>=0; i--)
        sum+= a[n-1-i][i];
    for(int i=0; i< n; i++)
        sum+= a[n/2][i],sum+= a[i][n/2] ;

    return sum - 3*(a[n/2][n/2]);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n" ;

    return 0;
}

