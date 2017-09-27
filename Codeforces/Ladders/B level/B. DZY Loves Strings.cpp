#include <bits/stdc++.h>

using namespace std;

int a[26];

int main(){

    string s; int k;

    cin >> s >> k;

    int x,maxi = -1;
    for(int i=0;i<26;i++)
        cin >> x, a[i]=x,maxi = maxi = max(maxi,x);

    long ans =0;
    for(int i=0;i<s.size();i++)
        ans= ans  +( (i+1)*a[ s[i]-'a' ] );

    for(int i=s.size()+1;i<=s.size()+k;i++)
        ans = ans + (maxi*i);

    cout << ans;
    return 0;
}
