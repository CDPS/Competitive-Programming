#include <bits/stdc++.h>

using namespace std;

typedef complex<double> pt;

int n;
pt a[256];

double memo[256][256][256];
double oo = 10000000;

double dp(int cur, int prev, int k){

    if(k>= n-cur)  return oo;
    if(cur == n-1) return abs(a[cur]-a[prev]);
    if(memo[cur][prev][k]!= -1.0) return memo[cur][prev][k];

    return memo[cur][prev][k] = min( abs(a[cur]-a[prev]) + dp(cur+1, cur,k),
                                     (k>0)? dp(cur+1,prev, k-1) : oo );
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
            cin >> x >> y, a[i] = pt(x,y);

        for(int i=0;i<256;i++)
            for(int j=0;j<256;j++)
                for(int k=0;k<256;k++)
                    memo[i][j][k] = -1.0;

        cout  << dp(1, 0 , k) << "\n";
    }

    return 0;
}
