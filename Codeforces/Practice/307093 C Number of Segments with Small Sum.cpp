#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main(){

    int n;
    long long s, acc = 0, ans = 0;

    cin >> n >> s;
    for(int i = 0; i<n; i++) cin >> a[i];

    for(int i=0,j=0;j<n;j++){
        acc += a[j];
        while(i<n && acc > s) acc-= a[i++];
        ans +=  j-i+1;
    }

    cout << ans << "\n";

    return 0;
}
