#include <bits/stdc++.h>

using namespace std;

int t, n, m;
string s;

bool solve(){

    cin >> n >> m;

    vector<bool> in_set(26, false);
    for(int i=0; i < n; i++)
        cin >> s, in_set[s[0]- 'a'] = true;

    bool check = true;
    while(m--){
        cin >> s;
        for(int i=0; i< s.size(); i++)
            check &= in_set[ s[i]-'A'];
    }
    return check;
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
       cout << ( solve()? "YES" : "NO") << "\n";
    
    return 0;
}