#include <bits/stdc++.h>

using namespace std;

int a[5000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){

        cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];

        long long ans = 0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                int maxi = max(2*a[j], a[n-1]);

                int l = 0, h = i-1, m;
                while(l< h){
                     m = l + ( (h-l)/2 );
                    if( a[m]  + a[i] + a[j] > maxi)
                         h = m;
                    else l = m +1;
                }

                if(a[l]+a[i]+a[j] > maxi)
                    ans += i-l;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
