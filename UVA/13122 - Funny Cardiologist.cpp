#include <bits/stdc++.h>

using namespace std;

int n;
complex<double> a[256];

double memo[256][256];
double oo = 10000000;

double dp(int idx, int w){

    if(w > n-idx) return oo;
    if(idx== n-1) return 0;
    if(memo[idx][w]!= -1.0) return memo[idx][w];

    double ans = oo;
    for(int i = idx + 1; i<n; i++)
        ans = min( abs(a[idx]- a[i]) + dp( i, w-1), ans);

    return memo[idx][w] = ans;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios_base::fixed);
    cout.precision(3);

    int k;

    while(cin >> n >> k){

        int x, y;
        for(int i=0;i<n;i++)
            cin >> x >> y, a[i] = complex<double>(x,y);

        for(int i=0;i<256;i++)
            for(int j=0;j<256;j++)
                memo[i][j] = -1.0;

        cout  << dp(0, n - k) << "\n";
    }
    return 0;
}
