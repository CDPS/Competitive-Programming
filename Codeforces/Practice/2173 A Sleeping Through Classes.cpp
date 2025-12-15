#include <bits/stdc++.h>

using namespace std;

int n, k, t;
string s;
int solve(){

    cin >> n >> k >> s;

    vector<bool> a(n, true);
    for(int i=0;i<n;i++)
        if(s[i] == '1' )
            for(int j =i; j <= min(n,i + k);j++ )
                a[j] = false;

    int ans = 0;
    for(int i=0;i<n;i++)
        ans+=a[i];
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

}
