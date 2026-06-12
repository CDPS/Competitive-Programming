#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[10];

int solve(){

    cin >> n;

    int maxi = -1;
    for(int i =0; i< n;i++)
        cin >> a[i], maxi = max(a[i], maxi);

    int ans = 0;
    for(int i =0; i< n;i++)
        ans+= a[i] == maxi;

    return ans;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
