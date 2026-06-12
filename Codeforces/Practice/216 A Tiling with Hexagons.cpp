#include <bits/stdc++.h>

using namespace std;

int t=1, a , b, c;

int solve(){

    cin >> a >> b >> c;

    return (c + a -1)*(b + a -1) - (a *(a-1));
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n" ;

    return 0;
}
