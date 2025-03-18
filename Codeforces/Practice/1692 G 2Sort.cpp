#include <bits/stdc++.h>

using namespace std;

int a[200001];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n , k;
    cin >> t;

    while(t--){

        cin >> n >> k;


        for(int i=1;i<=n;i++)
            cin >> a[i];

        int ans = 0;
        for(int i=1, j = 1;i<=n-k;i++){

            while(j <= n && a[j]*2 > a[j-1] ){
                if(j-i == k) break;
                j++;
            }

            if(j-i==k && a[j]*2 > a[j-1])
                ans++;
            else
                i = j-1, j++;
        }

        cout << ans << "\n";
    }
    return 0;
}
