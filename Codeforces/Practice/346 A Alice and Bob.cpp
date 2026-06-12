#include <bits/stdc++.h>

using namespace std;

int t = 1, n;

int a[100];

bool solve(){

    cin >> n;
    for(int i=0; i < n; i++) cin >> a[i];
    sort(a , a + n);

    int g = 0;
    for(int i=0; i < n ; i ++)
        g = __gcd(g, a[i]);

    return ( (a[n-1]/g) - n ) % 2;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << ( solve() ? "Alice" : "Bob" ) << "\n";

    return 0;
}
