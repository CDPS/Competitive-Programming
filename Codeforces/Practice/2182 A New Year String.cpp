#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

int solve(){

    cin >> n >> s;

    int ans = 0;
    for(int i=3;i<n;i++){
        if(s[i]=='5' && s[i-1]=='2' && s[i-2]=='0' && s[i-3]=='2')
            ans++;
    }

    int mini = 10;
    for(int i=3;i<n;i++){
        int curr = 0;
        curr += s[i]  !='6';
        curr += s[i-1]!='2';
        curr += s[i-2]!='0';
        curr += s[i-3]!='2';
        mini = min(curr, mini);
    }

    if(ans == 0 )
        return 0;
    if(mini == 0)
        return 0;
    if(mini == 4)
        return ans;

    return min(mini,ans);
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
