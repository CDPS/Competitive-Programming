#include <bits/stdc++.h>

using namespace std;

int a[200000];
int t,n;
long long x,y, acc;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--){

        cin >> n >> x >> y;

        acc = 0;
        for(int i=0;i<n;i++)
            cin >> a[i], acc += a[i];
        sort(a, a+n);

        long long ans = 0;
        for(int i=0;i<n;i++){
            if(acc - 2*a[i] >= x && acc - 2*a[i] <= y ) ans--;
            auto l = lower_bound(a, a+n, acc - y - a[i]);
            auto h = upper_bound(a, a+n, acc - x - a[i]);
            ans+=(h-l);
        }

        cout << ans/2 << "\n";
    }
    return 0;
}
