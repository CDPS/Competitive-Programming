#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int k;
ll n, m, xs, ys;
ll xcurr, ycurr;

ll solve(){

    cin >> n >> m >> xs >> ys >> k;

    ll ans=0;
    while(k--){

        cin >> xcurr >> ycurr;

        ll xsteps = 1e18, ysteps = 1e18;

        if(xcurr > 0 )
            xsteps =  (n - xs)/ (xcurr);
        if(xcurr < 0 )
            xsteps = (xs-1)/(-xcurr);

        if(ycurr > 0 )
            ysteps =  (m - ys)/ (ycurr);
        if(ycurr < 0 )
            ysteps = (ys-1)/(-ycurr);

        ll steps = min(ysteps, xsteps);
        xs+= xcurr*steps;
        ys+= ycurr*steps;
        ans+= steps;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
