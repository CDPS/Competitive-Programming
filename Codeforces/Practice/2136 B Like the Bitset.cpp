#include <bits/stdc++.h>

using namespace std;

int t, n, k;
string s;

bool check(){
    for(int i=0;i<n;i++){
        if(s[i]== '0') continue;
        int j = i;
        while(j<n && s[j]=='1')
            j++;
        if(j-i >= k) return false;
        i = j-1;
    }
    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--){

        cin  >> n >> k >> s;
        if(!check()){
            cout << "NO" << "\n";
            continue;
        }

        vector<int> ans(n);

        int curr = 1;
        for(int i=0;i<n;i++)
            if(s[i]=='1')
                ans[i] = curr++;
        for(int i=0;i<n;i++)
            if(s[i]=='0')
                ans[i] = curr++;

        cout << "YES" << "\n";
        for(int i=0;i<n;i++)
            cout << ans[i] << " \n"[i==n-1];

    }
    return 0;
}
