#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;

int solve(){

    cin >> n;

    ll maxi = -1, sum = 0, x;
    for(int i=0;i<n;i++)
        cin >> x, sum+=x, maxi= max(maxi, x);

    if(sum ==0 ) return 0;

    return (maxi * 2 <= sum)? 1 : (2ll*maxi)- sum;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--)
        cout << solve()<< "\n";
    return 0;
}
