#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, x;
    cin >> t;
    while(t--){

        cin >> n;
        int mini = 1e9, maxi = 0;
        for(int i=0;i<n;i++)
            cin >> x, mini = min(mini, x), maxi = max(maxi, x);

        cout << maxi - mini  << "\n";
    }

    return 0;
}
