#include <bits/stdc++.h>

using namespace std;

int a[15];

int main(){

    int n, l, r, x;
    cin >> n >> l >> r >> x;

    for(int i=0;i<n;i++) cin >> a[i];

    int ans = 0;
    for(int i=0;i<(1<<n);i++){
        int acc =0, ct = 0;
        int mini = 1e9, maxi = 0;
        for(int j=0;j<n;j++)
            if( (i&(1<<j)) !=0 )
               acc+= a[j], mini = min(mini, a[j]), maxi = max(maxi, a[j]), ct++;

        ans+= (acc >=l && acc <=r  && maxi-mini >= x && ct >=2);
    }

    cout << ans << "\n";

    return 0;
}

