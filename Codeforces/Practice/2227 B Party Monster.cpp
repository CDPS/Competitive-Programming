#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

bool solve(){

    cin >> n >> s;

    vector<int> acc(2, 0);
    for(int i=0; i < n; i++)
        acc[ s[i] =='(']++;

    return acc[0] == acc[1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";

    return 0;
}
