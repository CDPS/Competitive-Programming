#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, d;
int a[100000];

ll f(ll x){
    return (x*(x-1))/2ll;
}

ll solve(){

    cin >> n >> d;

    for(int i=0;i<n;i++)
        cin >> a[i];

    ll ans = 0;
    for(int i=0, j=0;j<n; j++){
        while( abs( a[j] - a[i] )  > d  )
                i++;
        ans += f(j-i);
    }
    return ans;
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
