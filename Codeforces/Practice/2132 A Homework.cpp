#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T, n, m;
string s, t, op;

string solve(){

    cin >> n >> s >> m >> t>> op;

    for(int i=0;i<m;i++)
        s= (op[i]=='D')? s + t[i] : t[i] + s;

    return s;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> T;
    while(T--)
        cout << solve() << "\n";

    return 0;
}
