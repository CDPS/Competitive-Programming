#include <bits/stdc++.h>

using namespace std;

int t = 1, n;
string s;
int acc[26];

int f(int x){
    return x*(x-1)/2;
}

int solve(){

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> s, acc[s[0]-'a']++;

    int ans = 0;
    for(int i=0;i<26;i++)
        ans+= f(acc[i]/2) + f(acc[i]/2 + (acc[i]%2));

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        cout << solve() << "\n" ;

    return 0;
}

