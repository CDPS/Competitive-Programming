#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n; string s;
    cin >> t;

    while(t--){
        cin >> n >> s;

        map<char, int> mp;
        int maxi = 0, mini = 100;

        for(int i=0;i<n;i++)
           mp[s[i]]++;

        for(auto it =mp.begin(); it!=mp.end();it++)
            maxi = max(maxi, it->second), mini = min(mini, it->second);

        int maxid=0;
        for(int i=0;i<n;i++)
            if(mp[s[i]] == maxi)
                maxid = i;

        int minid=maxid;
        for(int i=0;i<n;i++)
            if(mp[s[i]] == mini && s[maxid] != s[i])
                minid = i;

        s[minid] = s[maxid];
        cout << s << "\n";

    }
    return 0;
}

