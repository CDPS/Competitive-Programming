#include <bits/stdc++.h>

using namespace std;

long long a[100000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;

    cin >> t;

    while(t--){

        cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];

        int ans  = 0;

        for(int i=1;i<n;i++){
            if(a[i] < a[i-1]){
                long long b = a[i-1] - a[i];
                a[i] += b;
                for(int j=32;j>=0;j--){
                    if((b&(1ll<<j)) !=0){
                        ans =  max(ans, j + 1); break;
                    }
                }
            }
        }

        cout << ans << "\n";
    }


    return 0;
}

