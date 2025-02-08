#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;

    while(t--){

        cin >> n;
        int k = 1;
        for(int i=2;i*i<=n;i++)
            if(n%i==0)
                k = max(k, max(i, n/i));

        cout << k << " "<< n-k << "\n";
    }
    return 0;
}


