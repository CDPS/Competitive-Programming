#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,m;
    cin >> t;

    while(t--)
        cin >> n >> m ,cout << max(n,m) + 1 << "\n";

    return 0;
}
