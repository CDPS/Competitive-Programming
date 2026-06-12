#include <bits/stdc++.h>

using namespace std;

int n, t;
string a[1000];

string solve(){

    cin  >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    string ans = "";
    for(int i=0;i<n;i++)
        ans = min(ans + a[i], a[i] + ans);

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--)
        cout << solve() << "\n";

    return 0;
}
