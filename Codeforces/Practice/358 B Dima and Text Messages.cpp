#include <bits/stdc++.h>

using namespace std;

int n;

string s, t, wi;

bool solve(){

    cin >> n;

    t.reserve(300005);
    for(int i = 0; i < n; i++) {
        cin >> wi;
        t += "<3";
        t += wi;
    }
    t += "<3";
    cin >> s;

    int j = 0;
    for(int i=0; i< s.size() && j < t.size(); i++)
        if(s[i] == t[j])
            j++;

    return j == t.size();
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << (solve()? "yes" : "no" )<< "\n";

    return 0;
}
