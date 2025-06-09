#include <bits/stdc++.h>

using namespace std;

int a[200000];
int d[200001];
int oo = 1e9;

int main(){

    int n;
    cin >> n;

    for(int i=0;i<n;i++)
        cin >> a[i], d[i+1] = oo;
    d[0] = -oo;

    for(int i=0;i <n;i++){
        int l = upper_bound(d, d+n+1, a[i]) - d;
        if(d[l-1] < a[i] && a[i] < d[l])
            d[l] = a[i];
    }

    int ans = 0;
    for(int i=1;i<=n;i++)
        if(d[i]!=oo) ans = i;

    cout << ans << "\n";

    return 0;
}
