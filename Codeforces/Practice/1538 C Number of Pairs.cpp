#include <bits/stdc++.h>

using namespace std;

int a[200000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, l, r ;

    cin >> t;

    while(t--){

        cin >> n >> l >> r;

        for(int i=0;i<n;i++) cin >> a[i];
        sort(a, a+n);

        long long ans =0;
        for(int i=0;i<n;i++){
            int lower =  lower_bound(a + i + 1, a + n, l-a[i]) -a;
            int upper =  upper_bound(a + i + 1, a + n, r-a[i])-a; upper--;
            ans += upper - lower + 1 ;
        }

        cout << ans << "\n";
    }
    return 0;
}
