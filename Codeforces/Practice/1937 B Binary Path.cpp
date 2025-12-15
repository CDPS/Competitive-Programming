#include <bits/stdc++.h>

using namespace std;

int t, n;

string a[2];

void solve(){

    cin >> n >> a[0] >> a[1];

    int break_point = n-1;
    for(int i=0; i<n-1; i++)
        if(a[0][i+1] > a[1][i] ){
            break_point = i; break;
        }

    int equal_point = 0;
    for(int i=break_point-1;i>=0; i--)
        if(a[1][i] != a[0][i+1] ){
            equal_point = i + 1; break;
        }

    string ans  = "";
    int acc = 0;
    for(int i=0;i<= break_point; i++)
        ans+= a[0][i], acc += a[0][i] == '1';
    for(int i=break_point;i<n; i++)
        ans+= a[1][i], acc += a[1][i] == '1';

    cout << ans << "\n" << break_point - equal_point + 1 << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--)
        solve();

    return 0;
}
