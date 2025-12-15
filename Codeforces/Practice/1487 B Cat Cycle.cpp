#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int moveon(int start, int k) {
    return ((start - 1 + k ) % n) + 1;
}

int solve(){

    cin >> n >> m;

    if(n%2==0)
        return moveon(1, m-1);

    int collitions = (m-1)/(n/2);

    return moveon(1, m-1 + collitions);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--)
        cout << solve() << "\n";

    return 0;
}
