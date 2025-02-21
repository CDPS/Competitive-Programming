#include <bits/stdc++.h>

using namespace std;

int a[200000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, k ;

    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a, a + n);

    int ans = 0, i =0, j = n-1;
    while( i < j ){
        if(a[i] + a[j] > k) j--, ans++;
        else i++, j--, ans++;
    }

    cout << ans + (i==j) << "\n";
    return 0;
}
