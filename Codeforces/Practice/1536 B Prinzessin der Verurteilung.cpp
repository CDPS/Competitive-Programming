#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

string solve(){

    cin >> n >> s;

    set<string> st;
    for(int i=0;i<n;i++){
        string partial = "";
        for(int j=i;j<n;j++)
            partial+=s[j], st.insert(partial);
    }

    for(char i = 'a'; i<='z'; i++)
        if(!st.count(string({i})))
            return string({i});

    for(char i = 'a'; i<='z'; i++)
        for(char j = 'a'; j<='z'; j++)
            if(!st.count(string({i, j})))
                return string({i, j});

    for(char i = 'a'; i<='z'; i++)
        for(char j = 'a'; j<='z'; j++)
            for(char k = 'a'; k<='z'; k++)
                if(!st.count(string({i, j, k})))
                    return string({i, j, k});
    return "";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    while(t--)
        cout << solve() << "\n";

    return 0;
}
