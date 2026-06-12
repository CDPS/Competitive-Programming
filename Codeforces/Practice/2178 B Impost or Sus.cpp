#include <bits/stdc++.h>

using namespace std;

char const u = 'u';
char const s = 's';

int t;
string a;

int solve(){

    cin >> a;

    int n = a.size();

    int ans = 0;

    if(a[0] == u )   a[0] = s, ans++;
    if(a[n-1] == u ) a[n-1] = s, ans++;

    for(int i=1;i<n-1;i++){
        if(a[i] == u && a[i+1] ==u)
            ans++, a[i+1] = s;
    }
    return ans;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";
}

