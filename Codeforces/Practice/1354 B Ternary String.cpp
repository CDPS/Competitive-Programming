#include <bits/stdc++.h>

using namespace std;

int t;
string s;

int acc = 0;
map<char, int> mp;
void add(char x){ if(++mp[x]==1) acc++; }
void del(char x){ if(--mp[x]==0) acc--; }

int solve(){

    cin >> s;
    mp = map<char, int>();
    int n = s.size(), ans = n + 1;
    acc = 0;
    for(int i=0,j=0;j<n;j++){
        add(s[j]);
        while(i<n && acc == 3)
             ans= min(ans, j-i+1), del(s[i++]);
    }
    return ans == n + 1? 0 : ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
