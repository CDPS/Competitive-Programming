#include <bits/stdc++.h>

using namespace std;

int t = 1, n, k;

string s;

int solve(){

    cin >> n  >> k;

    int ans = 0;

    while(n--){

        cin >> s;

        vector<bool> v (10, false);
        for (char c : s)
            v[c-'0'] = true;

        bool check = true;
        for(int i=0;i<=k; i++)
            check &= v[i];

        ans+=check;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}

