#include <bits/stdc++.h>

using namespace std;

int freq[26];
int t = 1, n;
string s;

int solve(){

    cin >> n >> s;

    int ans = 0;
    for(int i=0;i<2*n-2;i++){
        if(isupper(s[i])){
            if(freq[ s[i]-'A']  == 0)
                ans++;
            else
                freq[ s[i]-'A']--;
        }else{
            freq[s[i]-'a']++;
        }
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
