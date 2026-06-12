#include <bits/stdc++.h>

using namespace std;

int t = 1, n, x;

bool solve(){

    cin >> n;

    bool check = false;
    for(int i=0; i<n;i++)
        cin >> x, check |= (x == 67);

    return check;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";

    return 0;
}

