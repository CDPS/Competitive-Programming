#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t , n , m;
    cin >> t;

    while(t--){

        cin >> n >> m;

        bool ans = false;

        if(m == n + 1){
            ans = true;
        }else{
            int k = (n + 1 - m)/9;
            ans = k>0 && (n+1-(9*k)) == m;
        }
        cout << (ans? "YES" : "NO") << "\n";
    }
    return 0;
}
