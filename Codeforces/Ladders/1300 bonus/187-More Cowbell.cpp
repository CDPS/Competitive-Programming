#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main(){

    int n,k,res;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        res = max(res, a[i]);
    }

    for(int i = 0; i < n - k; i++){
        res = max(res, a[i] + a[ 2 * (n - k) - 1 - i]);
    }
    cout << res << "\n";
    return 0;
}
