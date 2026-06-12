#include <bits/stdc++.h>

using namespace std;

int t = 1;

map<string,int> mp;
string pwd, s;

void solve(){

    cin >> pwd;
    for(int i=0;i<10;i++)
        cin >> s, mp[s] = i;

    for(int i=0;i<80;i+=10){
        string curr = pwd.substr(i, 10);
        cout<< mp[curr];
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}

