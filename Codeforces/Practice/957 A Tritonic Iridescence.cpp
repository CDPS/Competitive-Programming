#include <bits/stdc++.h>

using namespace std;

int n;
string s;

bool check(){
    for(int i=1;i<n;i++)
        if(s[i] != '?' && s[i] == s[i-1])
            return false;
    return true;
}

bool solve(){

    cin >> n >> s;

    if(!check()) return false;
    if(s[0] == '?' || s[n-1] == '?' ) return true;

    int acc = 0;
    for(int i=0;i<n;i++)
        acc = (s[i]== '?')? acc + 1 : acc;

    int curr  = 0;
    for(int i=1;i<n-1; i++)
        if(s[i] == '?' && s[i-1] != '?' && s[i+1] != '?'  && s[i-1] != s[i+1])
            curr ++;
    return curr != acc;
}


int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << (solve()? "YES" : "NO" ) << "\n";

    return 0;
}
