#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main(){

    int n; long long s;

    cin >> n >> s;
    for(int i = 0; i<n; i++) cin >> a[i];

    long long acc = 0;
    int ans = 0;
    for(int i=0,j=0;j<n;j++){
        acc += a[j];
        while(i<n && acc > s) acc-= a[i++];
        ans = max(ans, j-i+1);
    }

    cout << ans << "\n";

    return 0;
}
