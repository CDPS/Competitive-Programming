#include <bits/stdc++.h>

using namespace std;

int a[4];
int main(){

    string s;
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    cin >> s;
    int ans =0;
    for(int i=0;i<s.size();i++)
        ans+= a[ s[i]-'1' ];
    cout << ans << "\n";
    return 0;
}
