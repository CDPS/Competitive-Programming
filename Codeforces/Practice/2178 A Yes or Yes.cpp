#include <bits/stdc++.h>

using namespace std;

int t;
string s;

bool solve(){

    cin >> s;
    int acc = 0;
    for(int i =0;i < s.size() ; i ++ )
        acc += s[i] == 'Y';

    return acc <= 1;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";
}
