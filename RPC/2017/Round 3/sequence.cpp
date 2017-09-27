#include <bits/stdc++.h>

using namespace std;

const string endline = "\n";

int main() {

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long t, n, ans;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << (n*n) + 2*n << endline;
    }

    return 0;
}
