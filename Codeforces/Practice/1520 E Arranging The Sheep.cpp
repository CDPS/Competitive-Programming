#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n; string s;
    cin >> t;

    while(t--){

        cin >> n >> s;

        map<int, int> mp; int sheeps = 1;
        for(int i=0;i<n;i++)
            if(s[i]=='*')
                mp[sheeps++] = i;

        long long ans = 0;
        for(int i=1;i<sheeps;i++)
            ans += abs(mp[sheeps/2] - mp[i]) - abs(sheeps/2- i);

        cout << ans << "\n";
    }
    return 0;
}
