#include <bits/stdc++.h>

using namespace std;

int t, n, q;
string s;

void solve(){

    cin >> n >> q >> s;

    int i=0, j = n-1, l=0, r=0;

    for(int k=0; k<q; k++){
        char op = s[k];
        if(op == '0') i++;
        if(op == '1') j--;
        if(op == '2') r++, l++;
    }

    if(l + i + (n-1-j) == n){
        for(int k=0;k<n;k++)
            cout << '-';
        cout << "\n";
        return;
    }

    vector<char> ans (n, '+');

    for(int k=0;k<i;k++)
        ans[k] = '-';
    for(int k=n-1; k > j; k--)
        ans[k] = '-';
    for(int k=0;k<l;k++)
        ans[i + k] = '?';
    for(int k=0;k<r;k++)
        ans[j - k] = '?';

    for(int k=0;k<n;k++)
        cout << ans[k];
    cout << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
         solve();

    return 0;
}

