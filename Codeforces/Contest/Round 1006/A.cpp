#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    string s;
    int t , n , k, p;
    cin >> t;

    while(t--){
        cin >> n >> k >> p;
        if(k<0) k*=-1;
        int ans = k/p + (k%p!=0);
        if( ans > n ) ans = -1;
        cout << ans << "\n";
    }
    return 0;
}
