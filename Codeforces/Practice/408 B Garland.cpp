#include <bits/stdc++.h>

using namespace std;

int t = 1;

string a, b;

int ca[26], cb[26];

int solve(){

    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    for(int i=0; i < n;i++)
        ca[ a[i]-'a' ]++;
    for(int i=0; i < m;i++)
        cb[ b[i]-'a' ]++;

    int ans = 0;
    for(int i=0;i<26; i++){
        if(ca[i] == 0 && cb[i] > 0)
            return -1;
        ans += min(ca[i], cb[i]);
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
