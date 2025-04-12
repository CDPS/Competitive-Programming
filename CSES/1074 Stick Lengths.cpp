#include <bits/stdc++.h>

using namespace std;

int a[200000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];

    sort(a, a + n);

    long long ans = 0;
    for(int i=0;i<n;i++)
        ans += abs(a[n/2]-a[i]);

    cout << ans  << "\n";

    return 0;
}
