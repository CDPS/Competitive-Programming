#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    for(int i=0;i<n;i++) cin >> a[i];

    int ans = 0, acc = 0;
    for(int i=0, j = 0; j < n ; j++){
        acc += a[j];
        while(i < n && acc > k ) acc-= a[i++];
        ans= max(ans, j-i+1);
    }

    cout << ans  << "\n";

    return 0;
}

