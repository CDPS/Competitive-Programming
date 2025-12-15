#include <bits/stdc++.h>

using namespace std;

string a, b;

bool f(string &s){
    for(int i=0;i<s.size();i++)
        if(s[i]!= '0')
            return false;
    return true;
}

bool solve(){

    cin >> a >> b;

    if(a.size() != b.size())
        return false;

    return f(a) == f(b);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout <<  (solve()? "YES" : "NO" ) << "\n";
    return 0;
}
