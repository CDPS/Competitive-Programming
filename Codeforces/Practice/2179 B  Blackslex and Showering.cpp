#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
int a[200000];

ll solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];


    ll sum = 0;
    for(int i=1;i<n;i++)
        sum += abs(a[i]-a[i-1]);

    ll ans = 1e9;
    for(int i = 1; i < n -1; i++)
        ans = min(ans,  sum-abs(a[i]-a[i-1])-abs(a[i]-a[i+1]) + abs(a[i-1] - a[i+1]) );

    return  min ( {ans, sum - abs(a[0] - a[1]),  sum - abs(a[n-1] - a[n-2]) });
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";
}


