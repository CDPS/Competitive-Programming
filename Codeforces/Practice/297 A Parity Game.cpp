#include <bits/stdc++.h>

using namespace std;

int t = 1, n, m;

string a, b;

bool solve(){

    cin >> a >> b;

    n = a.size();
    m = b.size();

    int ones_a = 0, ones_b = 0;
    for(int i=0; i < n; i++) ones_a+= a[i] == '1';
    for(int i=0; i < m; i++) ones_b+= b[i] == '1';

    return ones_b <= ones_a + ones_a%2;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";

    return 0;
}

