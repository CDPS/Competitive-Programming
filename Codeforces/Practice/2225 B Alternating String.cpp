#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;
bool solve(){

    cin >> s;

    int acc = 0;
    for(int i=0; i < s.size()-1; i++)
        acc+= s[i] == s[i+1];

    return acc<=2;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO" ) << "\n";

    return 0;
}
