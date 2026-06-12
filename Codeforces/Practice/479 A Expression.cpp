#include <bits/stdc++.h>

using namespace std;

int t =1, a, b, c;

int solve(){

    cin >> a >> b >> c;

    return max({a+b+c, a*b*c , (a*b) + c, a+(b*c), (a+b)*c, a*(b+c) });
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    while(t--)
        cout << solve() << "\n" ;

    return 0;
}
