#include <bits/stdc++.h>

using namespace std;

int a[200000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,k;
    cin >> t;

    while(t--){

        cin >> n >> k;
        for(int i=0;i<n;i++) cin >> a[i];

        for(int i=30;i>=0;i--){
            int acc = 0;
            for(int j=0;j<n;j++)
                acc += ((a[j] & (1<<i) )== 0);
            if(k>= acc){
               k-=acc;
               for(int j=0;j<n;j++)
                a[j] |= (1<<i);
            }
        }


        int ans  = ( 1 <<31)-1;
        for(int i=0;i<n;i++) ans&= a[i];

        cout << ans << "\n";
    }

    return 0;
}
