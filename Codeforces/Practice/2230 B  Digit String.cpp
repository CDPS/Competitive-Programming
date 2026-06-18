#include <bits/stdc++.h>

using namespace std;

int t;
string s;

int solve(){

    cin >> s;

    int n = s.size();

    int four_count = 0;
    for(int i=0; i < n; i++)
        four_count += (s[i] == '4');

    vector<int> pfx(n + 2, 0);
    for(int i=1 ; i <=n; i++){
        if(s[i-1]=='1' || s[i-1] == '3')
            pfx[i] = 1;
        pfx[i] += pfx[i-1];
    }

    vector<int> sfx(n + 2, 0);
    for(int i= n; i >=1; i-- ){
        if(s[i-1] == '2')
            sfx[i]  = 1;
        sfx[i] += sfx[i+1];
    }

    int ans = 1e9;
    for(int i = 1; i <=n; i++)
        ans = min( ans,  pfx[i-1] + sfx[i+1]);

    return ans + four_count;
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
       cout << solve() << "\n";

    return 0;
}