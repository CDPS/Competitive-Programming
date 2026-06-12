#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

int f(string x){
    int ans = 1;
    for(int i=1;i< n;i++)
        if(x[i]!=x[i-1])
            ans++;
    return ans;
}

int solve(){

    cin >> n >> s;

    int ans = f(s);
    for(int i=1; i< n;i++)
        ans = max(ans, f(s.substr(i) + s.substr(0, i)));

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

