#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[200000];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    sort(a, a+n);

    ll acc = 0;
    for(int i=0;i<n;i++) acc += a[i];

    if(acc - a[n-1] < a[n-1] )
        cout << a[n-1] * 2 << "\n";
    else
        cout << acc << "\n";

    return 0;
}
