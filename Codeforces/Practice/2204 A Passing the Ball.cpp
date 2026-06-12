#include <bits/stdc++.h>

using namespace std;

int t, n;

string s;

int solve(){
    cin >> n >> s;
    return s.find('L') + 1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n" ;

    return 0;
}
