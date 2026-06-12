#include <bits/stdc++.h>

using namespace std;

int n;
int a[100000];
int b[100000];

bool solve(){

    cin >> n;
    for(int i=0; i < n;i++)
        cin >> a[i], b[i] = a[i];
    sort(b, b + n);

    vector<bool> check(n);
    for(int i=0; i < n; i++)
        check[i] = a[i] == b[i];

    for(int i=0; i <n; i++)
        if(__gcd(a[i], b[0]) == b[0])
            check[i] = true;

    for(int i=0;i < n; i++)
        if(!check[i])
            return false;

    return true;
}

int t;
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (  solve()? "YES" : "NO" ) << "\n";

    return 0;
}
