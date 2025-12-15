#include <bits/stdc++.h>

using namespace std;

int t, n;
string s; char c;

void solve(){

    cin >> n >> c >> s;

    bool all_equal = true;
    for(int i=0;i<n && all_equal ;i++)
        all_equal &= s[i]==c;

    if(all_equal){
        cout << 0 << "\n";
        return;
    }

    for(int i=n/2;i<n;i++)
        if(s[i]==c){
            cout << 1 << "\n" << i+1 << "\n"; return;
        }

    cout << 2 << "\n" << n << " " << n-1 << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();
    return 0;
}
