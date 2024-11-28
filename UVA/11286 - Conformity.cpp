#include <bits/stdc++.h>

using namespace std;

string a[5];

string f(){
    string ans = "";
    for(int j=0;j<5;j++)
        ans+= a[j];
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n;
    while(cin >> n && n){

        int maxi = 0;
        map<string, int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++) cin >> a[j];
            sort(a, a +5);
            maxi = max(maxi,++mp[f()]);
        }

        int ans =0;
        for(auto it=mp.begin();it!=mp.end();it++)
            ans = ( it->second == maxi)? ans + it->second : ans;

        cout << ans << "\n";
    }

    return 0;
}
