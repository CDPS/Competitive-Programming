#include <bits/stdc++.h>

using namespace std;

int a[200000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];
    sort(a, a + n);

    long long ans = 1;
    for(int i=0;i<n;i++){
        if(a[i] > ans ) break;
        ans += a[i];
    }

    cout << ans  << "\n";

    return 0;
}

