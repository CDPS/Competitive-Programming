#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int t,n,m,k;
    cin >> t;

    while(t--){
        cin >> n >> m >> k;

        if( max(n-m, m-n) > k || max(n, m) < k){
            cout << "-1" << "\n";
            continue;
        }

        char c  = (n>m)? '0' : '1';
        char cp = (n>m)? '1' : '0';

        map<char,int> mp = {{c, max(n,m)},{cp, min(n,m)}};
        string ans = "";
        int temp = 0;
        for(int i=0;i< n+m;i++){
            if(temp < k  && mp[c] >0){
                cout << c, temp++; mp[c]--;
            }else{
                cout << cp; temp--;
            }
        }

        cout << "\n";
    }
    return 0;
}
