#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[200001];

bool solve(){

    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];

    if((2*a[1] - a[2])%(n+1) != 0 ) return false;

    int y = (2*a[1] - a[2])/(1+n);
    int x = a[1] - (y*n);

    if(x < 0 || y < 0) return false;

    for(int i=1;i<=n;i++)
        if(a[i] != (i*x) +  ( (n-i+1)*y ))
            return false;

    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO" ) << "\n";
    return 0;
}
