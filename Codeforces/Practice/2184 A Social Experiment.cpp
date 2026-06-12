#include <bits/stdc++.h>

using namespace std;

int t = 1, n;

int solve(){

    cin >> n;

    if(n == 2 || n == 3) return n;

    return n%2;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n" ;

    return 0;
}

