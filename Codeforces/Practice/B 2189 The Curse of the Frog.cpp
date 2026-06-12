#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
ll x, a, b, c;

ll solve(){

    cin >> n >> x;

    ll curr_distance = 0, max_gain = -1e18;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        curr_distance += (b-1)*a;
        max_gain = max(max_gain, b*a-c);
    }

    if(curr_distance >= x)
        return 0;
    if(max_gain <= 0)
        return -1;

    return ( (x-curr_distance) + (max_gain-1))/max_gain;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

