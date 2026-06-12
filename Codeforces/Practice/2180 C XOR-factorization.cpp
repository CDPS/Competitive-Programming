#include <bits/stdc++.h>

using namespace std;

int t, k, n;

void solve(){

    cin >> n >> k;

    vector<int> a(k);

    if(k%2){
        for(int i=0;i<k;i++)
            a[i] = n;
    }else{
        for(int i = 30, p = 0; i >= 0; i--) {
            if( (n&(1<<i)) != 0 ){
                for(int j = 0; j < k; j++)
                    if( j != min(p, k-1))
                        a[j] += (1 << i);

                p = min(p + 1, k );

            } else {
                for(int j = 0; j < p/2*2; j++)
                    a[j] += (1 << i);
            }
        }
    }

    for(int i=0;i<k;i++)
        cout << a[i] << " \n"[i==k-1];
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
