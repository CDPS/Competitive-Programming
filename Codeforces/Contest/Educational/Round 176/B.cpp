#include<bits/stdc++.h>

using namespace std;

int a[50001];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, k;
    cin >> t;

    while(t--){

        cin >> n >> k;

        for(int i=0;i<n;i++) cin >> a[i];

        long long ans = 0;
        if(k == 1){

             int maxi = 0, idx =0;
             for(int i=0;i<n;i++){
                if(a[i] > maxi )
                    maxi = a[i], idx = i;
                if(maxi == a[i] && (i==n-1 || i==0) )
                    idx = i;
             }

             if(idx == n-1 || idx == 0){
                int maxi2 = 0;
                for(int i=0;i<n;i++)
                    if(i!= idx)
                        maxi2 = max(a[i],maxi2);
                ans = maxi + maxi2;
             }
             else{
                ans = max( maxi + a[0], maxi + a[n-1]);
             }
        }else{
            sort(a, a+n, greater<int>());
            for(int i=0;i<=k;i++)
            ans += a[i];
        }

        cout << ans << "\n";
    }
    return 0;
}

