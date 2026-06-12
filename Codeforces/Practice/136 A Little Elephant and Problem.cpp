#include <bits/stdc++.h>

using namespace std;

int t = 1, n;
int a[100000];
int b[100000];

bool solve(){

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i], b[i] = a[i];

    sort(b, b + n);

    int acc = 0;
    for(int i=0;i<n;i++)
        acc += (b[i]!=a[i]);

    return acc <=2;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";

    return 0;
}
