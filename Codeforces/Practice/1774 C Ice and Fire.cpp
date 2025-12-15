#include <bits/stdc++.h>

using namespace std;

int last[2];

int t, n;
string s;

void solve(){

    cin >> n >> s;

    last[0] = last[1] = 0;
    for(int i=0;i<n-1;i++){
        last[s[i]- '0'] = i + 1;
        cout << ( (s[i]== '1')? last[0] + 1 : last[1] + 1 )<< " \n"[i==n-2];
    }
}

int main(){

     cin.sync_with_stdio(false); cin.tie(NULL);

     cin >> t;
     while(t--)
        solve();
}
