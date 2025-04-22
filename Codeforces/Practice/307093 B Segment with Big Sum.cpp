#include <bits/stdc++.h>

using namespace std;

int a[100000];
int oo = 1e9 + 7;

int main(){

    int n; long long s;

    cin >> n >> s;
    for(int i = 0; i<n; i++) cin >> a[i];

    long long acc = 0;
    int ans = oo;
    for(int i=0,j=0;j<n;j++){
        acc += a[j];
        while(i<n && acc >= s)
            ans = min(ans, j-i+1), acc-= a[i++];
    }

    cout << (ans==oo? -1: ans)  << "\n";

    return 0;
}
