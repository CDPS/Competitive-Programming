#include <bits/stdc++.h>

using namespace std;

int a[200000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){

        cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];

        int needed = 0, have = INT_MAX, acc = 0, x;

        for(int i=0;i<n;i++){
            cin >> x;
            if(x>a[i]) needed = x-a[i], acc++;
            else have = min(have, a[i] - x);
        }

        cout << ( (acc <= 1 && have>=needed)? "YES" : "NO" ) << "\n";
    }
    return 0;
}
