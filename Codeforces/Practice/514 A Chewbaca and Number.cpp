#include <bits/stdc++.h>

using namespace std;

int t = 1, n;
string s;

char mp[10] = { '9', '8', '7', '6', '5', '4', '3', '2', '1', '0' };

string solve(){

    cin >> s;
    n = s.size();

    char mini = min( s[0], mp[  s[0] - '0'] );
    if(mini  != '0')
        s[0] = mini;

    for(int i=1;i < n; i++)
       s[i] =  min( s[i], mp[ s[i] - '0'] );

    return s;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}

