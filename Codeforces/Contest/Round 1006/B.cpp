#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n; string s;
    cin >> t;

    while(t--){

        cin >> n  >> s;

        map<char, ll> mp;

        for(int i=0;i<n;i++) mp[s[i]]++;

        ll  a = mp['-']/2;
        ll  b = mp['-']/2 + mp['-']%2;
        ll  c = mp['_'];

        cout << a*b*c << "\n";
    }
    return 0;
}
