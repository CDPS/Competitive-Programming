#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, k;
    cin >> t;

    while(t--){

        cin >> n >> k;
        for(int i=0;i<n-2;i++)
            cout << (k%2? n : n-1) << " ";
        cout << n << " " << n-1 << "\n";
    }
    return 0;
}
