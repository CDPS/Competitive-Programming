#include <bits/stdc++.h>

using namespace std;

int t, n;

int ans[200000];
string s;

void solve(){

    cin >> n >> s;

    for(int i=0;i<n;i++){

        if(s[i] == '1' ){
            ans[i] = i + 1;
            continue;
        }

        int j = i;
        while(j < n && s[j] == '0')
            j++;

        if(j-i==1){
            cout << "NO" << "\n";
            return;
        }

        for(int k=i; k< j; k++)
            ans[k] = j - k + i;

        i = j -1;
    }


    cout << "YES" << "\n";
    for(int i=0;i<n;i++)
        cout << ans[i] << " \n"[i==n-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
