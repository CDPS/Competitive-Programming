#include <bits/stdc++.h>

using namespace std;

long long a[200001];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, x;
    cin >> t;

    while(t--){

        cin >> n;

        for(int i=0;i<=n;i++) a[i] = 0;

        for(int i=0;i<n;i++)
            cin >> x, a[x]++;

        long long ans = 0;

        for(int i=1;i<=n;i++){
            ans += a[i-1]*(a[i]*(a[i]-1))/2;
            ans += a[i]*(a[i-1]*(a[i-1]-1))/2;
            ans += (a[i]*(a[i]-1)*(a[i]-2))/ 6;
        }

        for(int i=2;i<=n;i++){
            ans += a[i-2]*(a[i]*(a[i]-1))/2;
            ans += a[i]*(a[i-2]*(a[i-2]-1))/2;
            ans += a[i]*a[i-1]*a[i-2];
        }

        cout << ans << "\n";
    }

    return 0;
}
