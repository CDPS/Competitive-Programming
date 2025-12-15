#include <bits/stdc++.h>

using namespace std;

string s;

int solve(){

    cin >> s;

    int ans = 0, n = s.size();

    for(int i=0;i< n-1;i++)
        if(s[i] == 'h' && s[i+1] == 'a')
            ans++;

    for(int i=0;i<n-4;i++)
        if(s[i] == 'b' && s[i+1] == 'r' && s[i+2] == 'a' && s[i+3] == 'v' && s[i+4] == 'o')
            ans+=3;

    for(int i=0;i<n-4;i++)
        if(s[i] == 'b' && s[i+1] == 'o' && s[i+2] == 'o' && s[i+3] == 'o' && s[i+4] == 'o')
            ans-=1;

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}


